/* This file was generated by ODB, object-relational mapping (ORM)
 * compiler for C++.
 */

DROP TABLE IF EXISTS `TemplateReactionRegulation`;

CREATE TABLE `TemplateReactionRegulation` (
  `unipaxId` BIGINT UNSIGNED NOT NULL PRIMARY KEY)
 ENGINE=InnoDB;

ALTER TABLE `TemplateReactionRegulation`
  ADD CONSTRAINT `TemplateReactionRegulation_unipaxId_fk`
    FOREIGN KEY (`unipaxId`)
    REFERENCES `Control` (`unipaxId`)
    ON DELETE CASCADE;

