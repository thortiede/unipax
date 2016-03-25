/* This file was generated by ODB, object-relational mapping (ORM)
 * compiler for C++.
 */

DROP TABLE IF EXISTS `PhenotypeVocabulary`;

CREATE TABLE `PhenotypeVocabulary` (
  `unipaxId` BIGINT UNSIGNED NOT NULL PRIMARY KEY,
  `patoData` TEXT NOT NULL)
 ENGINE=InnoDB;

ALTER TABLE `PhenotypeVocabulary`
  ADD CONSTRAINT `PhenotypeVocabulary_unipaxId_fk`
    FOREIGN KEY (`unipaxId`)
    REFERENCES `ControlledVocabulary` (`unipaxId`)
    ON DELETE CASCADE;

