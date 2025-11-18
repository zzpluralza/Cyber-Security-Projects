$originalfile = ""
$outputfile = ""
$malwarearray = 'Clear 1.', 'Driver Support One', 'EpiStart', 'OneBrowser', 'OneLaunch', 'OneStart', 'PC App Store', 'PC Helpsoft', 'PDF_Spark', 'PDFSpark', 'PDFSuperHero', 'PDFTool', 'PDFHub', 'PDFlex', 'WaveBrowser', 'WebNavigator', 'Shift 11', 'ShiftBrowser', 'ZipThis', 'ZipCrunch', 'ZoomInfo'

$ColumnNamesSource = 'NAME', 'FRIENDLY_NAME', 'DEVICE_TYPE', 'SITE_NAME', 'SITE_UNIQUE_ID', 'OS', 'IP_ADDRESS', 'APPLICATION_NAME', 'VERSION', 'PUBLISHER', 'INSTALL_DATE', 'LAST_LOGGED_ON_USER', 'DATE_CHECKED'


import-csv $originalfile |
