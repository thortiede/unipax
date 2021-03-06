/* This file was generated by ODB, object-relational mapping (ORM)
 * compiler for C++.
 */

DROP TABLE IF EXISTS `EvidenceCodeVocabulary`;

CREATE TABLE `EvidenceCodeVocabulary` (
  `unipaxId` BIGINT UNSIGNED NOT NULL PRIMARY KEY)
 ENGINE=InnoDB;

ALTER TABLE `EvidenceCodeVocabulary`
  ADD CONSTRAINT `EvidenceCodeVocabulary_unipaxId_fk`
    FOREIGN KEY (`unipaxId`)
    REFERENCES `ControlledVocabulary` (`unipaxId`)
    ON DELETE CASCADE;

