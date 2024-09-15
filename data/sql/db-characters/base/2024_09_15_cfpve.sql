DROP TABLE IF EXISTS `mod_crossfaction_pve`;
CREATE TABLE IF NOT EXISTS `mod_crossfaction_pve` (
  `instanceID` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `factionID` int(10) unsigned NOT NULL,
  `date` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`instanceID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
