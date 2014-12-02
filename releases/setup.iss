﻿; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

#define MyAppName "Grabber"
#define MyAppVersion "4.0.2"
#define MyAppPublisher "Bionus"
#define MyAppURL "http://code.google.com/p/imgbrd-grabber/"
#define MyAppExeName "Grabber.exe"

[Setup]
; NOTE: The value of AppId uniquely identifies this application.
; Do not use the same AppId value in installers for other applications.
; (To generate a new GUID, click Tools | Generate GUID inside the IDE.)
AppId={{8C007AE6-3F7D-41CC-AB7C-75C08C276EC8}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
;AppVerName={#MyAppName} {#MyAppVersion}
AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}
DefaultDirName={pf}\{#MyAppName}
DefaultGroupName={#MyAppName}
AllowNoIcons=yes
LicenseFile=D:\Programmation\C++\Qt\Grabber\releases\Apache license 2.0.txt
OutputDir=D:\Programmation\C++\Qt\Grabber\releases
OutputBaseFilename=Grabber_{#MyAppVersion}
SetupIconFile=D:\Programmation\C++\Qt\Grabber\images\icon.ico       
UninstallDisplayName="{#MyAppName} {#MyAppVersion}"
UninstallDisplayIcon={app}\icon.ico
WizardSmallImageFile=D:\Programmation\C++\Qt\Grabber\icon.bmp
Compression=lzma
SolidCompression=yes
ChangesAssociations=yes         

[CustomMessages] 
english.IGL=Imageboard-Grabber Links
french.IGL=Liens Imageboard-Grabber

[Registry]
Root: HKCR; Subkey: ".igl"; ValueType: string; ValueName: ""; ValueData: "Imageboard-Grabber"; Flags: uninsdeletevalue 
Root: HKCR; Subkey: "Imageboard-Grabber"; ValueType: string; ValueName: ""; ValueData: "{cm:IGL}"; Flags: uninsdeletekey
Root: HKCR; Subkey: "Imageboard-Grabber\DefaultIcon"; ValueType: string; ValueName: ""; ValueData: "{app}\{#MyAppExeName},0"
Root: HKCR; Subkey: "Imageboard-Grabber\shell\open\command"; ValueType: string; ValueName: ""; ValueData: """{app}\{#MyAppExeName}"" ""%1""" 

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"
Name: "brazilianportuguese"; MessagesFile: "compiler:Languages\BrazilianPortuguese.isl"
Name: "catalan"; MessagesFile: "compiler:Languages\Catalan.isl"
Name: "czech"; MessagesFile: "compiler:Languages\Czech.isl"
Name: "danish"; MessagesFile: "compiler:Languages\Danish.isl"
Name: "dutch"; MessagesFile: "compiler:Languages\Dutch.isl"
Name: "finnish"; MessagesFile: "compiler:Languages\Finnish.isl"
Name: "french"; MessagesFile: "compiler:Languages\French.isl"
Name: "german"; MessagesFile: "compiler:Languages\German.isl"
Name: "hebrew"; MessagesFile: "compiler:Languages\Hebrew.isl"
Name: "hungarian"; MessagesFile: "compiler:Languages\Hungarian.isl"
Name: "italian"; MessagesFile: "compiler:Languages\Italian.isl"
Name: "japanese"; MessagesFile: "compiler:Languages\Japanese.isl"
Name: "norwegian"; MessagesFile: "compiler:Languages\Norwegian.isl"
Name: "polish"; MessagesFile: "compiler:Languages\Polish.isl"
Name: "portuguese"; MessagesFile: "compiler:Languages\Portuguese.isl"
Name: "russian"; MessagesFile: "compiler:Languages\Russian.isl"
Name: "slovenian"; MessagesFile: "compiler:Languages\Slovenian.isl"
Name: "spanish"; MessagesFile: "compiler:Languages\Spanish.isl"   

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked
Name: "quicklaunchicon"; Description: "{cm:CreateQuickLaunchIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked; OnlyBelowVersion: 0,6.1 

[Files]                                                           
Source: "D:\Programmation\C++\Qt\Grabber\images\icon.ico"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\Programmation\C++\Qt\Grabber\release\CDR.exe"; DestDir: "{app}"; Flags: ignoreversion   
Source: "D:\Programmation\C++\Qt\Grabber\release\CrashReporter.exe"; DestDir: "{app}"; Flags: ignoreversion   
Source: "D:\Programmation\C++\Qt\Grabber\release\Grabber.exe";  DestDir: "{app}"; Flags: ignoreversion   
Source: "D:\Programmation\C++\Qt\Grabber\release\words.txt";    DestDir: "{app}";    
Source: "D:\Programmation\C++\Qt\Grabber\release\icudt52.dll";  DestDir: "{app}"; Flags: ignoreversion         
Source: "D:\Programmation\C++\Qt\Grabber\release\icuin52.dll";  DestDir: "{app}"; Flags: ignoreversion         
Source: "D:\Programmation\C++\Qt\Grabber\release\icuuc52.dll";  DestDir: "{app}"; Flags: ignoreversion         
Source: "D:\Programmation\C++\Qt\Grabber\release\libeay32.dll"; DestDir: "{app}"; Flags: ignoreversion         
Source: "D:\Programmation\C++\Qt\Grabber\release\libEGL.dll";   DestDir: "{app}"; Flags: ignoreversion         
Source: "D:\Programmation\C++\Qt\Grabber\release\libGLESv2.dll";    DestDir: "{app}"; Flags: ignoreversion         
Source: "D:\Programmation\C++\Qt\Grabber\release\libmysql.dll";     DestDir: "{app}"; Flags: ignoreversion        
Source: "D:\Programmation\C++\Qt\Grabber\release\qscintilla2.dll";  DestDir: "{app}"; Flags: ignoreversion      
Source: "D:\Programmation\C++\Qt\Grabber\release\Qt5Core.dll";      DestDir: "{app}"; Flags: ignoreversion
Source: "D:\Programmation\C++\Qt\Grabber\release\Qt5Gui.dll";       DestDir: "{app}"; Flags: ignoreversion           
Source: "D:\Programmation\C++\Qt\Grabber\release\Qt5Multimedia.dll";    DestDir: "{app}"; Flags: ignoreversion       
Source: "D:\Programmation\C++\Qt\Grabber\release\Qt5Network.dll";       DestDir: "{app}"; Flags: ignoreversion          
Source: "D:\Programmation\C++\Qt\Grabber\release\Qt5PrintSupport.dll";  DestDir: "{app}"; Flags: ignoreversion      
Source: "D:\Programmation\C++\Qt\Grabber\release\Qt5Script.dll";  DestDir: "{app}"; Flags: ignoreversion        
Source: "D:\Programmation\C++\Qt\Grabber\release\Qt5Sql.dll";     DestDir: "{app}"; Flags: ignoreversion           
Source: "D:\Programmation\C++\Qt\Grabber\release\Qt5Widgets.dll"; DestDir: "{app}"; Flags: ignoreversion           
Source: "D:\Programmation\C++\Qt\Grabber\release\Qt5Xml.dll";     DestDir: "{app}"; Flags: ignoreversion           
Source: "D:\Programmation\C++\Qt\Grabber\release\ssleay32.dll";   DestDir: "{app}"; Flags: ignoreversion     
Source: "D:\Programmation\C++\Qt\Grabber\release\crashreporter\English.qm";   DestDir: "{app}\crashreporter"; Flags: ignoreversion         
Source: "D:\Programmation\C++\Qt\Grabber\release\crashreporter\Français.qm";  DestDir: "{app}\crashreporter"; Flags: ignoreversion  
Source: "D:\Programmation\C++\Qt\Grabber\release\imageformats\qdds.dll";  DestDir: "{app}\imageformats"; Flags: ignoreversion
Source: "D:\Programmation\C++\Qt\Grabber\release\imageformats\qgif.dll";  DestDir: "{app}\imageformats"; Flags: ignoreversion      
Source: "D:\Programmation\C++\Qt\Grabber\release\imageformats\qicns.dll"; DestDir: "{app}\imageformats"; Flags: ignoreversion
Source: "D:\Programmation\C++\Qt\Grabber\release\imageformats\qico.dll";  DestDir: "{app}\imageformats"; Flags: ignoreversion   
Source: "D:\Programmation\C++\Qt\Grabber\release\imageformats\qjp2.dll";  DestDir: "{app}\imageformats"; Flags: ignoreversion
Source: "D:\Programmation\C++\Qt\Grabber\release\imageformats\qjpeg.dll"; DestDir: "{app}\imageformats"; Flags: ignoreversion
Source: "D:\Programmation\C++\Qt\Grabber\release\imageformats\qmng.dll";  DestDir: "{app}\imageformats"; Flags: ignoreversion
Source: "D:\Programmation\C++\Qt\Grabber\release\imageformats\qsvg.dll";  DestDir: "{app}\imageformats"; Flags: ignoreversion
Source: "D:\Programmation\C++\Qt\Grabber\release\imageformats\qtga.dll";  DestDir: "{app}\imageformats"; Flags: ignoreversion
Source: "D:\Programmation\C++\Qt\Grabber\release\imageformats\qtiff.dll"; DestDir: "{app}\imageformats"; Flags: ignoreversion
Source: "D:\Programmation\C++\Qt\Grabber\release\imageformats\qwbmp.dll"; DestDir: "{app}\imageformats"; Flags: ignoreversion   
Source: "D:\Programmation\C++\Qt\Grabber\release\imageformats\qwebp.dll"; DestDir: "{app}\imageformats"; Flags: ignoreversion
Source: "D:\Programmation\C++\Qt\Grabber\release\languages\English.qm";   DestDir: "{app}\languages"; Flags: ignoreversion         
Source: "D:\Programmation\C++\Qt\Grabber\release\languages\Français.qm";  DestDir: "{app}\languages"; Flags: ignoreversion    
Source: "D:\Programmation\C++\Qt\Grabber\release\languages\Russian.qm";   DestDir: "{app}\languages"; Flags: ignoreversion   
Source: "D:\Programmation\C++\Qt\Grabber\release\platforms\qminimal.dll"; DestDir: "{app}\platforms"; Flags: ignoreversion
Source: "D:\Programmation\C++\Qt\Grabber\release\platforms\qoffscreen.dll"; DestDir: "{app}\platforms"; Flags: ignoreversion
Source: "D:\Programmation\C++\Qt\Grabber\release\platforms\qwindows.dll";   DestDir: "{app}\platforms"; Flags: ignoreversion                  
Source: "D:\Programmation\C++\Qt\Grabber\release\sqldrivers\qsqlite.dll";   DestDir: "{app}\sqldrivers"; Flags: ignoreversion               
Source: "D:\Programmation\C++\Qt\Grabber\release\sqldrivers\qsqlmysql.dll"; DestDir: "{app}\sqldrivers"; Flags: ignoreversion               
Source: "D:\Programmation\C++\Qt\Grabber\release\sqldrivers\qsqlodbc.dll";  DestDir: "{app}\sqldrivers"; Flags: ignoreversion               
Source: "D:\Programmation\C++\Qt\Grabber\release\sqldrivers\qsqlpsql.dll";  DestDir: "{app}\sqldrivers"; Flags: ignoreversion    
Source: "D:\Programmation\C++\Qt\Grabber\release\sites\Booru-on-rails\icon.png";  DestDir: "{localappdata}\Bionus\Grabber\sites\Booru-on-rails"; Flags: ignoreversion
Source: "D:\Programmation\C++\Qt\Grabber\release\sites\Booru-on-rails\model.xml"; DestDir: "{localappdata}\Bionus\Grabber\sites\Booru-on-rails"; Flags: ignoreversion
Source: "D:\Programmation\C++\Qt\Grabber\release\sites\Booru-on-rails\sites.txt"; DestDir: "{localappdata}\Bionus\Grabber\sites\Booru-on-rails";   
Source: "D:\Programmation\C++\Qt\Grabber\release\sites\Danbooru\icon.png";        DestDir: "{localappdata}\Bionus\Grabber\sites\Danbooru"; Flags: ignoreversion
Source: "D:\Programmation\C++\Qt\Grabber\release\sites\Danbooru\model.xml";       DestDir: "{localappdata}\Bionus\Grabber\sites\Danbooru"; Flags: ignoreversion
Source: "D:\Programmation\C++\Qt\Grabber\release\sites\Danbooru\sites.txt";       DestDir: "{localappdata}\Bionus\Grabber\sites\Danbooru";   
Source: "D:\Programmation\C++\Qt\Grabber\release\sites\Danbooru\behoimi.org\settings.ini";              DestDir: "{localappdata}\Bionus\Grabber\sites\Danbooru\behoimi.org";
Source: "D:\Programmation\C++\Qt\Grabber\release\sites\Danbooru\chan.sankakucomplex.com\settings.ini";  DestDir: "{localappdata}\Bionus\Grabber\sites\Danbooru\chan.sankakucomplex.com";
Source: "D:\Programmation\C++\Qt\Grabber\release\sites\Danbooru\idol.sankakucomplex.com\settings.ini";  DestDir: "{localappdata}\Bionus\Grabber\sites\Danbooru\idol.sankakucomplex.com";    
Source: "D:\Programmation\C++\Qt\Grabber\release\sites\Danbooru (2.0)\icon.png";  DestDir: "{localappdata}\Bionus\Grabber\sites\Danbooru (2.0)"; Flags: ignoreversion
Source: "D:\Programmation\C++\Qt\Grabber\release\sites\Danbooru (2.0)\model.xml"; DestDir: "{localappdata}\Bionus\Grabber\sites\Danbooru (2.0)"; Flags: ignoreversion
Source: "D:\Programmation\C++\Qt\Grabber\release\sites\Danbooru (2.0)\sites.txt"; DestDir: "{localappdata}\Bionus\Grabber\sites\Danbooru (2.0)";   
Source: "D:\Programmation\C++\Qt\Grabber\release\sites\Gelbooru (0.1)\icon.png";  DestDir: "{localappdata}\Bionus\Grabber\sites\Gelbooru (0.1)"; Flags: ignoreversion
Source: "D:\Programmation\C++\Qt\Grabber\release\sites\Gelbooru (0.1)\model.xml"; DestDir: "{localappdata}\Bionus\Grabber\sites\Gelbooru (0.1)"; Flags: ignoreversion
Source: "D:\Programmation\C++\Qt\Grabber\release\sites\Gelbooru (0.1)\sites.txt"; DestDir: "{localappdata}\Bionus\Grabber\sites\Gelbooru (0.1)";     
Source: "D:\Programmation\C++\Qt\Grabber\release\sites\Gelbooru (0.2)\icon.png";  DestDir: "{localappdata}\Bionus\Grabber\sites\Gelbooru (0.2)"; Flags: ignoreversion
Source: "D:\Programmation\C++\Qt\Grabber\release\sites\Gelbooru (0.2)\model.xml"; DestDir: "{localappdata}\Bionus\Grabber\sites\Gelbooru (0.2)"; Flags: ignoreversion      
Source: "D:\Programmation\C++\Qt\Grabber\release\sites\Gelbooru (0.2)\sites.txt"; DestDir: "{localappdata}\Bionus\Grabber\sites\Gelbooru (0.2)";     
Source: "D:\Programmation\C++\Qt\Grabber\release\sites\Gelbooru (0.2)\gelbooru.com\settings.ini"; DestDir: "{localappdata}\Bionus\Grabber\sites\Gelbooru (0.2)\gelbooru.com";     
Source: "D:\Programmation\C++\Qt\Grabber\release\sites\Metabooru\icon.png";   DestDir: "{localappdata}\Bionus\Grabber\sites\Metabooru"; Flags: ignoreversion
Source: "D:\Programmation\C++\Qt\Grabber\release\sites\Metabooru\model.xml";  DestDir: "{localappdata}\Bionus\Grabber\sites\Metabooru"; Flags: ignoreversion
Source: "D:\Programmation\C++\Qt\Grabber\release\sites\Metabooru\sites.txt";  DestDir: "{localappdata}\Bionus\Grabber\sites\Metabooru";     
Source: "D:\Programmation\C++\Qt\Grabber\release\sites\Moebooru\icon.png";  DestDir: "{localappdata}\Bionus\Grabber\sites\Metabooru"; Flags: ignoreversion
Source: "D:\Programmation\C++\Qt\Grabber\release\sites\Moebooru\model.xml"; DestDir: "{localappdata}\Bionus\Grabber\sites\Metabooru"; Flags: ignoreversion
Source: "D:\Programmation\C++\Qt\Grabber\release\sites\Moebooru\sites.txt"; DestDir: "{localappdata}\Bionus\Grabber\sites\Metabooru";     
Source: "D:\Programmation\C++\Qt\Grabber\release\sites\Shimmie\icon.png";   DestDir: "{localappdata}\Bionus\Grabber\sites\Shimmie"; Flags: ignoreversion
Source: "D:\Programmation\C++\Qt\Grabber\release\sites\Shimmie\model.xml";  DestDir: "{localappdata}\Bionus\Grabber\sites\Shimmie"; Flags: ignoreversion
Source: "D:\Programmation\C++\Qt\Grabber\release\sites\Shimmie\sites.txt";  DestDir: "{localappdata}\Bionus\Grabber\sites\Shimmie";
Source: "D:\Programmation\C++\Qt\Grabber\release\sites\Zerochan\icon.png";  DestDir: "{localappdata}\Bionus\Grabber\sites\Zerochan"; Flags: ignoreversion
Source: "D:\Programmation\C++\Qt\Grabber\release\sites\Zerochan\model.xml"; DestDir: "{localappdata}\Bionus\Grabber\sites\Zerochan"; Flags: ignoreversion     
Source: "D:\Programmation\C++\Qt\Grabber\release\sites\Zerochan\sites.txt"; DestDir: "{localappdata}\Bionus\Grabber\sites\Zerochan";         

[InstallDelete]         
Type: filesandordirs; Name: "{app}\languages\updater"
Type: filesandordirs; Name: "{app}\sites"    
Type: files; Name: "{app}\Updater.exe"       
Type: files; Name: "{app}\VERSION"
Type: files; Name: "{app}\MD5"         
Type: files; Name: "{app}\libgcc_s_dw2-1.dll"                    
Type: files; Name: "{app}\QtCore4.dll"                       
Type: files; Name: "{app}\QtGui4.dll"                       
Type: files; Name: "{app}\QtNetwork4.dll"                       
Type: files; Name: "{app}\QtScript4.dll"                       
Type: files; Name: "{app}\QtSql4.dll"                       
Type: files; Name: "{app}\QtXml4.dll"                 
Type: files; Name: "{app}\imageformats\qgif4.dll"                             
Type: files; Name: "{app}\imageformats\qico4.dll"                             
Type: files; Name: "{app}\imageformats\qjpeg4.dll"                             
Type: files; Name: "{app}\imageformats\qmng4.dll"                             
Type: files; Name: "{app}\imageformats\qsvg4.dll"                             
Type: files; Name: "{app}\imageformats\qtga4.dll"                             
Type: files; Name: "{app}\imageformats\qtiff4.dll"                             
Type: files; Name: "{app}\sqldrivers\qsqlmysql4.dll"    

[UninstallDelete]
Type: filesandordirs; Name: "{%UserProfile}\Grabber"

[Icons]
Name: "{group}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{group}\{cm:UninstallProgram,{#MyAppName}}"; Filename: "{uninstallexe}"
Name: "{commondesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon
Name: "{userappdata}\Microsoft\Internet Explorer\Quick Launch\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: quicklaunchicon

[Run]
Filename: "{app}\{#MyAppExeName}"; Description: "{cm:LaunchProgram,{#StringChange(MyAppName, "&", "&&")}}"; Flags: nowait postinstall skipifsilent

