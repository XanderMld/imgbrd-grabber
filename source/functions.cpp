#include <QSettings>
#include <QFile>
#include <QMessageBox>
#include <QDir>
#include <QFileInfo>
#include <QProcess>
#include <QStandardPaths>
#include <QApplication>
#include <QDebug>
#include <QDesktopServices>
#include <QUrl>
#include "math.h"
#include "functions.h"
//#include "mainwindow.h"

using namespace std;

//extern QMap<QDateTime,QString> _log;
//extern mainWindow *_mainwindow;
extern QMap<QString,QString> _md5;



/**
 * Popup a message notifying the user that something went wrong.
 * @param	parent	The parent widget
 * @param	error	The error message
 */
void error(QWidget *parent, QString error)
{ QMessageBox::critical(parent, "Error", error); }

/**
 * Sort a list non case-sensitively.
 * @param   sList   The list that will be ordered
 */
void sortNonCaseSensitive(QStringList &sList)
{
	QMap<QString, QString> strMap;
	foreach (QString str, sList)
	{ strMap.insert( str.toLower(), str); }
	sList = strMap.values();
}

/**
 * Load custom tokens from settings.
 * @return	The map with token names as keys and token tags as values.
 */
QMap<QString,QStringList> getCustoms()
{
	QMap<QString,QStringList> tokens;
	QSettings settings(savePath("settings.ini"), QSettings::IniFormat);
	settings.beginGroup("Save/Customs");
	QStringList keys = settings.childKeys();
	for (int i = 0; i < keys.size(); i++)
	{ tokens.insert(keys.at(i), settings.value(keys.at(i)).toString().split(' ')); }
	return tokens;
}

/**
 * Load multiple filenames from settings.
 * @return	The map with token names as keys and token tags as values.
 */
QMap<QString,QString> getFilenames()
{
	QMap<QString,QString> tokens;
	QSettings settings(savePath("settings.ini"), QSettings::IniFormat);
	settings.beginGroup("Filenames");
	QStringList keys = settings.childKeys();
	for (int i = 0; i < keys.size(); i++)
	{
		if (!keys.at(i).isEmpty())
		{ tokens.insert(keys.at(i), settings.value(keys.at(i)).toString()); }
	}
	return tokens;
}

/**
 * Convert a danbooru-like date (Sat May 14 17:38:04 -0400 2011) to a valid QDateTime.
 * @param	str				The date string.
 * @param	timezonedecay	The number of timezones between the user and the server.
 * @return	The converted date as a QDateTime.
 */
QDateTime qDateTimeFromString(QString str, int timezonedecay)
{
	QDateTime date;
	if (str[0].isDigit())
	{
		date = QDateTime::fromString(str.left(19), "yyyy/MM/dd HH:mm:ss");
		date = date.addSecs(str.mid(str.length() - 5).toInt() * 36);
	}
	else
	{
		QStringList months = QStringList() << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun" << "Jul" << "Aug" << "Sep" << "Oct" << "Nov" << "Dec";
		QTime time = QTime::fromString(str.mid(11, 8), "HH:mm:ss");
		date.setDate(QDate(str.mid(26,4).toInt(), months.indexOf(str.mid(4,3))+1, str.mid(8,2).toInt()+(str.mid(11,2).toInt() >= 18)));
		date.setTime(time.addSecs(3600 * timezonedecay));
	}
	return date;
}

/**
 * Load md5 file and put its content into the _md5 map.
 */
void loadMd5s()
{
	QFile f(savePath("md5s.txt"));
	if (f.open(QFile::ReadOnly))
	{
		QString line;
		while ((line = f.readLine()) != "")
			_md5.insert(line.left(32), line.mid(32));
		f.close();
	}
}

/**
 * Save the _md5 map to the md5 file.
 */
void saveMd5s()
{
	QFile f(savePath("md5s.txt"));
	if (f.open(QFile::WriteOnly | QFile::Truncate))
	{
		QStringList md5s = _md5.keys();
		QStringList paths = _md5.values();
		for (int i = 0; i < md5s.size(); i++)
			f.write(QString(md5s[i] + paths[i] + "\r\n").toUtf8());
		f.close();
	}
}

/**
 * Append a md5 to the md5 file.
 */
void saveMd5(QString md5, QString path)
{
	QFile f(savePath("md5s.txt"));
	if (f.open(QFile::WriteOnly | QFile::Append))
	{
		f.write(QString(md5 + path + "\r\n").toUtf8());
		f.close();
	}
}

/**
 * Check if a file with this md5 already exists;
 * @param	md5		The md5 that needs to be checked.
 * @return			A QString containing the path to the already existing file, an empty QString if the md5 does not already exists.
 */
QString md5Exists(QString md5)
{
	if (_md5.contains(md5))
	{
		if (QFile::exists(_md5[md5]))
			return _md5[md5];

		removeMd5(md5);
	}
	return QString();
}

/**
 * Adds a md5 to the _md5 map and adds it to the md5 file.
 * @param	md5		The md5 to add.
 * @param	path	The path to the image with this md5.
 */
void addMd5(QString md5, QString path)
{
	_md5.insert(md5, path);
	saveMd5(md5, path);
}

/**
 * Set a md5 to the _md5 map changing the file it is pointing to.
 * @param	md5		The md5 to add.
 * @param	path	The path to the image with this md5.
 */
void setMd5(QString md5, QString path)
{
	bool cont = _md5.contains(md5);
	_md5[md5] = path;

	if (cont)
		saveMd5s();
	else
		saveMd5(md5, path);
}

/**
 * Removes a md5 from the _md5 map and removes it from the md5 file.
 * @param	md5		The md5 to remove.
 */
void removeMd5(QString md5)
{
	_md5.remove(md5);
	saveMd5s();
}

QString getUnit(int *value)
{
	QString unit = "o";
	if (*value >= 1024)
	{
		*value /= 1024;
		if (*value >= 1024)
		{
			*value /= 1024;
			unit = "Mio";
		}
		else
		{ unit = "Kio"; }
	}
	return unit;
}
QString getUnit(float *value)
{
	QString unit = "o";
	if (*value >= 1024)
	{
		*value /= 1024;
		if (*value >= 1024)
		{
			*value /= 1024;
			unit = "Mio";
		}
		else
		{ unit = "Kio"; }
	}
	return unit;
}

/**
 * Load favorites from local file.
 * @return	A QMap<QString,QString> with tags as keys, then the remaining details as value (value1|value2|value3...)
 */
QMap<QString,QString> loadFavorites()
{
	QMap<QString,QString> favorites;
	QFile file(savePath("favorites.txt"));
	if (file.open(QIODevice::ReadOnly))
	{
		QString favs = file.readAll();
		QStringList wrds = favs.replace("\r\n", "\n").replace("\r", "\n").split("\n");
		for (int i = 0; i < wrds.count(); i++)
		{
			if (!wrds.at(i).isEmpty())
			{
				QStringList xp = wrds.at(i).split("|");
				QString tag = xp.takeFirst();
				favorites.insert(tag, (xp.isEmpty() ? "" : xp.join("|")));
			}
		}
		file.close();
	}
	return favorites;
}

/**
 * Load view it later tags from local file.
 * @return	A QStringList containing tags to view later
 */
QStringList loadViewItLater()
{
	QStringList viewitlater;
	QFile file(savePath("viewitlater.txt"));
	if (file.open(QIODevice::ReadOnly))
	{
		QString vil = file.readAll();
		viewitlater = vil.replace("\r\n", "\n").replace("\r", "\n").split("\n");
		file.close();
	}
	return viewitlater;
}

/**
 * Load ignored tags from local file.
 * @return	A QStringList containing tags
 */
QStringList loadIgnored()
{
	QStringList ignore;
	QFile file(savePath("ignore.txt"));
	if (file.open(QIODevice::ReadOnly))
	{
		QString vil = file.readAll();
		ignore = vil.replace("\r\n", "\n").replace("\r", "\n").split("\n");
		file.close();
	}
	return ignore;
}

/**
 * Check filename format's validity.
 * @param	text	The format to be validated.
 * @return			A QString containing the message (error or not).
 * @todo			Return a constant instead of a QString.
 */
QString validateFilename(QString text)
{
	// Field must be filled
	if (text.isEmpty())
	{ return QObject::tr("<span style=\"color:red\">Les noms de fichiers ne doivent pas être vides !</span>"); }
#ifdef Q_OS_WIN
	// Check for invalid windows characters
	if (text.contains(':') || text.contains('*') || text.contains('?') || text.contains('"') || text.contains('<') || text.contains('>') || text.contains('|'))
		return QObject::tr("<span style=\"color:red\">Votre format contient des caractères interdits sur windows ! Caractères interdits : * ? \" : < > |</span>");
#endif
	// Can't validate javascript expressions
	if (text.startsWith("javascript:"))
	{ return QObject::tr("<span style=\"color:orange\">Impossible de valider les expressions Javascript.</span>"); }
	// Field must end by an extension
	if (!text.endsWith(".%ext%"))
	{ return QObject::tr("<span style=\"color:orange\">Votre nom de fichier ne finit pas par une extension, symbolisée par %ext% ! Vous risquez de ne pas pouvoir ouvrir vos fichiers.</span>"); }
	// Field must contain an unique token
	if (!text.contains("%md5%") && !text.contains("%id%") && !text.contains("%count"))
	{ return QObject::tr("<span style=\"color:orange\">Votre nom de fichier n'est pas unique à chaque image et une image risque d'en écraser une précédente lors de la sauvegarde ! Vous devriez utiliser le symbole %md5%, unique à chaque image, pour éviter ce désagrément.</span>"); }
	// Looking for unknown tokens
	QStringList tokens = QStringList() << "artist" << "general" << "copyright" << "character" << "model" << "filename" << "rating" << "md5" << "website" << "ext" << "all" << "id" << "search" << "search_(\\d+)" << "allo" << getCustoms().keys() << "date" << "date:([^%]+)" << "score" << "count(:\\d+)?(:\\d+)?";
	QRegExp rx("%(.+)%");
	rx.setMinimal(true);
	int pos = 0;
	while ((pos = rx.indexIn(text, pos)) != -1)
	{
		bool found = false;
		for (int i = 0; i < tokens.length(); i++)
		{
			if (QRegExp("%"+tokens[i]+"%").indexIn(rx.cap(0)) != -1)
			{ found = true; }
		}
		if (!found)
		{ return QObject::tr("<span style=\"color:orange\">Le symbole %%1% n\'existe pas et ne sera pas remplacé.</span>").arg(rx.cap(1)); }
		pos += rx.matchedLength();
	}
	// Check if code is unique
	if (!text.contains("%md5%") && !text.contains("%website%") && !text.contains("%count"))
		return QObject::tr("<span style=\"color:green\">Vous avez choisi d'utiliser le symbole %id%. Sachez que celui-ci est unique pour un site choisi. Le même ID pourra identifier des images différentes en fonction du site.</span>");
	// All tests passed
	return QObject::tr("<span style=\"color:green\">Format valide !</span>");
}

/**
 * Return the path to a specified file in the config folder (since program files is not writable).
 * @param	file	The file.
 * @return			The absolute path to the file.
 */
QString savePath(QString file)
{
	if (QFile(QDir::toNativeSeparators(qApp->applicationDirPath()+"/settings.ini")).exists())
	{ return QDir::toNativeSeparators(qApp->applicationDirPath()+"/"+file); }
	if (QFile(QDir::toNativeSeparators(QDir::homePath()+"/Grabber/settings.ini")).exists())
	{ return QDir::toNativeSeparators(QDir::homePath()+"/Grabber/"+file); }
	return QDir::toNativeSeparators(QStandardPaths::writableLocation(QStandardPaths::DataLocation)+"/"+file);
}

/**
 * Return the levenshtein distance between two strings.
 * @param	s1	First string.
 * @param	s2	Second string.
 * @return		The levenshtein distance between s1 and s2.
 */
int levenshtein(QString s1, QString s2)
{
	const size_t len1 = s1.size(), len2 = s2.size();
	std::vector<std::vector<unsigned int> > d(len1 + 1, vector<unsigned int>(len2 + 1));

	d[0][0] = 0;
	for(unsigned int i = 1; i <= len1; ++i) d[i][0] = i;
	for(unsigned int i = 1; i <= len2; ++i) d[0][i] = i;

	for(unsigned int i = 1; i <= len1; ++i)
		for (unsigned int j = 1; j <= len2; ++j)
			d[i][j] = std::min( std::min(d[i - 1][j] + 1,d[i][j - 1] + 1),
				d[i - 1][j - 1] + (s1[i - 1] == s2[j - 1] ? 0 : 1) );

	return d[len1][len2];
}

/**
 * Opens the file explorer and select the file.
 * @param	pathIn	The path to the file.
 */
void showInGraphicalShell(const QString &pathIn)
{
	// Mac & Windows support folder or file.
	#if defined(Q_OS_WIN)
		QString param;
		if (!QFileInfo(pathIn).isDir())
		{ param = QLatin1String("/select,"); }
		param += QDir::toNativeSeparators(pathIn);
		QProcess::startDetached("explorer.exe "+param);
	#elif defined(Q_OS_MAC)
		Q_UNUSED(parent)
		QStringList scriptArgs;
		scriptArgs << QLatin1String("-e") << QString::fromLatin1("tell application \"Finder\" to reveal POSIX file \"%1\"").arg(pathIn);
		QProcess::execute(QLatin1String("/usr/bin/osascript"), scriptArgs);
		scriptArgs.clear();
		scriptArgs << QLatin1String("-e") << QLatin1String("tell application \"Finder\" to activate");
		QProcess::execute("/usr/bin/osascript", scriptArgs);
	#else
		QDesktopServices::openUrl(QUrl("file:///"+pathIn));
	#endif
}

/**
 * Converts a QFont to a CSS string.
 * @param	font	The font to convert.
 * @return	The CSS font.
 */
QString qfonttocss(QFont font)
{
	QString style;
	switch (font.style())
	{
		case QFont::StyleNormal:	style = "normal";	break;
		case QFont::StyleItalic:	style = "italic";	break;
		case QFont::StyleOblique:	style = "oblique";	break;
	}
	QString size;
	if (font.pixelSize() == -1)
	{ size = QString::number(font.pointSize())+"pt"; }
	else
	{ size = QString::number(font.pixelSize())+"px"; }
	QString weight = QString::number(font.weight()*8); // should be "font.weight()*8+100", but linux doesn't handle weight the same way windows do
	QStringList decorations;
	if (font.strikeOut())	{ decorations.append("line-through");	}
	if (font.underline())	{ decorations.append("underline");		}
	return "font-family:'"+font.family()+"'; font-size:"+size+"; font-style:"+style+"; font-weight:"+weight+"; text-decoration:"+(decorations.isEmpty() ? "none" : decorations.join(" "))+";";
}

/**
 * Converts a DOM elemet to a map.
 * @param	dom		The DOM element to convert.
 * @return	A QString map with names (joined with a slash if necessary) as keys and texts as values.
 */
QMap<QString,QString> domToMap(QDomElement dom)
{
	QMap<QString,QString> details;
	dom.firstChildElement("Name").firstChild().nodeValue();
	for (QDomNode n = dom.firstChild(); !n.isNull(); n = n.nextSibling())
	{
		if (n.firstChild().nodeName() == "#text")
		{ details[n.nodeName()] = n.firstChild().nodeValue(); }
		else
		{
			QMap<QString,QString> r = domToMap(n.toElement());
			QStringList k = r.keys();
			for (int i = 0; i < r.count(); i++)
			{ details[n.nodeName()+"/"+k.at(i)] = r.value(k.at(i)); }
		}
	}
	return details;
}

/**
 * Append text in the log in a new line.
 * @param	l	The message to append.
 */
QFile f, fCommandsLog, fCommandsSqlLog;
void log(QString l, Log)
{
	if (!f.isOpen())
	{
		f.setFileName(savePath("main.log"));
		f.open(QFile::Append | QFile::Text | QFile::Truncate);
	}

	QDateTime time = QDateTime::currentDateTime();
	QSettings set(savePath("settings.ini"), QSettings::IniFormat);

	QString v = set.contains("Login/pseudo") && !set.value("Login/pseudo").toString().isEmpty() ? l.replace(set.value("Login/pseudo").toString(), "{pseudo}") : l;
	v = set.contains("Login/password") && !set.value("Login/password").toString().isEmpty() ? l.replace(set.value("Login/password").toString(), "{password}") : v;
	f.write(QString("["+time.toString("hh:mm:ss.zzz")+"] "+stripTags(v)+"\r\n").toUtf8());
	f.flush();

	//_log.insert(time, (type == Error ? QObject::tr("<b>Erreur :</b> %1").arg(l) : (type == Warning ? QObject::tr("<b>Attention :</b> %1").arg(l) : (type == Notice ? QObject::tr("<b>Notice :</b> %1").arg(l) : l))));
	//_mainwindow->logShow();

	qDebug() << time.toString("hh:mm:ss.zzz") << l;
}
void logCommand(QString l)
{
	if (!fCommandsLog.isOpen())
	{
		fCommandsLog.setFileName(savePath("commands.log"));
		fCommandsLog.open(QFile::Append | QFile::Text | QFile::Truncate);
	}

	fCommandsLog.write(QString(l+"\r\n").toUtf8());
	fCommandsLog.flush();
}
void logCommandSql(QString l)
{
	if (!fCommandsSqlLog.isOpen())
	{
		fCommandsSqlLog.setFileName(savePath("commands.sql"));
		fCommandsSqlLog.open(QFile::Append | QFile::Text | QFile::Truncate);
	}

	fCommandsSqlLog.write(QString(l+"\r\n").toUtf8());
	fCommandsSqlLog.flush();
}

/**
 * Removes HTML from a string.
 * @param	str		The string to remove HTML from.
 * @return			The string without html.
 */
QString stripTags(QString str)
{ return str.remove(QRegExp("<[^>]*>")); }

/**
 * Append text in the log at the end of the current line.
 * @param	l	The message to append.
 */
void logUpdate(QString l)
{
	/*QDateTime date = _log.keys().at(_log.count()-1);
	QString message = _log.value(date)+l;
	_log.insert(date, message);
	_mainwindow->logShow();

	qDebug() << l;*/
}

/**
 * Shut down computer after a certain period of time.
 * @param	timeout		Time before shutdown in seconds.
 */
void shutDown(int timeout)
{
	#if defined(Q_OS_WIN)
		QProcess::startDetached("shutdown -s -f -t "+QString::number(timeout));
	#else
		QProcess::startDetached("shutdown "+QString::number(timeout));
	#endif
}

/**
 * Opens CD tray.
 */
void openTray()
{
	#if defined(Q_OS_WIN)
		QProcess::startDetached("CDR.exe open");
	#else
		QProcess::startDetached("eject cdrom");
	#endif
}

/**
 * Rounds a var to the closest integer.
 * @param	d	Number of decimals to keep.
 */
float round(float n, int d)
{
	int p = pow(10., d);
	return floor(n * p + .5) / p;
}

void clearLayout(QLayout *layout)
{
	QLayoutItem *item;
	while((item = layout->takeAt(0)))
	{
		if (item->layout())
		{
			clearLayout(item->layout());
			delete item->layout();
		}
		delete item->widget();
		delete item;
	}
}

QString mapToString(QMap<QString,QString> map, QString gen, QString mid)
{ return QStringList(map.keys()).join(gen)+mid+QStringList(map.values()).join(gen); }

QMap<QString,QString> stringToMap(QString map, QString gen, QString mid)
{
	QStringList keysValues = map.split(mid);
	QStringList keys = keysValues.at(0).split(gen), values = keysValues.at(1).split(gen);
	QMap<QString,QString> res = QMap<QString,QString>();
	for (int i = 0; i < qMax(keys.size(), values.size()); i++)
	{ res.insert(keys[i], values[i]); }
	return res;
}

QString getExtension(QString url)
{
	QString ext;
	if (url.contains('.'))
	{
		ext = url.section('.', -1);
		if (ext.contains('?'))
			ext = ext.section('?', 0, -2);
	}
	return ext;
}

QString setExtension(QString url, QString extension)
{
	int pPos = url.lastIndexOf('.');
	if (pPos != -1)
	{
		int qPos = url.indexOf('?', pPos);
		if (qPos != -1)
			url.replace(pPos + 1, qPos - pPos - 1, extension);
		else
			url = url.left(pPos) + "." + extension;
	}
	return url;
}
