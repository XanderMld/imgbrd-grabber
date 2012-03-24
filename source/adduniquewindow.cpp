#include "adduniquewindow.h"
#include "functions.h"
#include "json.h"
#include "ui_adduniquewindow.h"
#include <QtXml>



/**
 * Constructor of the AddUniqueWindow class, generating its window.
 * @param	favorites	List of favorites tags, needed for coloration
 * @param	parent		The parent window
 */
AddUniqueWindow::AddUniqueWindow(QString selected, QMap<QString,QMap<QString,QString> > sites, mainWindow *parent) : QDialog(parent), ui(new Ui::AddUniqueWindow), m_parent(parent), m_sites(sites)
{
	ui->setupUi(this);

	ui->comboSites->addItems(m_sites.keys());
	ui->comboSites->setCurrentIndex(m_sites.keys().indexOf(selected));

	QSettings settings(savePath("settings.ini"), QSettings::IniFormat);
	ui->lineFolder->setText(settings.value("Save/path").toString());
	ui->lineFilename->setText(settings.value("Save/filename").toString());
}

/**
 * Ui events
 */
void AddUniqueWindow::on_buttonFolder_clicked()
{
	QString folder = QFileDialog::getExistingDirectory(this, tr("Choisir un dossier de sauvegarde"), ui->lineFolder->text());
	if (!folder.isEmpty())
	{ ui->lineFolder->setText(folder); }
}
void AddUniqueWindow::on_lineFilename_textChanged(QString text)
{ ui->labelFilename->setText(validateFilename(text)); }

/**
 * Search for image in available websites.
 */
void AddUniqueWindow::add()
{ ok(false); }
void AddUniqueWindow::ok(bool close)
{
	m_close = close;
	m_page = new Page(&m_sites, ui->comboSites->currentText(), QStringList() << (ui->lineId->text().isEmpty() ? "md5:"+ui->lineMd5->text() : "id:"+ui->lineId->text()) << "status:any", 1, 1);
	connect(m_page, SIGNAL(finishedLoading(Page*)), this, SLOT(replyFinished(Page*)));
	m_page->load();
}

/**
 * Signal triggered when the search is finished.
 * @param r		The QNetworkReply associated with the search
 */
void AddUniqueWindow::replyFinished(Page *p)
{
	if (p->images().isEmpty())
	{
		error(this, tr("Aucune image n'a été trouvée."));
		return;
	}

	Image *img = p->images().first();
	QStringList tags;
	foreach (Tag tag, img->tags())
	{ tags.append(tag.text()); }

	QMap<QString,QString> values;
	values.insert("id", QString::number(img->id()));
	values.insert("md5", img->md5());
	values.insert("rating", img->rating());
	values.insert("tags", tags.join(" "));
	values.insert("file_url", img->fileUrl().toString());
	values.insert("site", ui->comboSites->currentText());

	values.insert("page_url", m_sites[ui->comboSites->currentText()]["Urls/Html/Post"]);
	QString t = m_sites[ui->comboSites->currentText()].contains("DefaultTag") ? m_sites[ui->comboSites->currentText()]["DefaultTag"] : "";
	values["page_url"].replace("{tags}", t);
	values["page_url"].replace("{id}", values["id"]);

	m_parent->batchAddUnique(values);

	if (m_close)
	{ this->close(); }
}
