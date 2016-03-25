/* This file was generated by ODB, object-relational mapping (ORM)
 * compiler for C++.
 */

DROP TABLE IF EXISTS `Dna_entityReference`;

DROP TABLE IF EXISTS `Dna`;

CREATE TABLE `Dna` (
  `unipaxId` BIGINT UNSIGNED NOT NULL PRIMARY KEY)
 ENGINE=InnoDB;

CREATE TABLE `Dna_entityReference` (
  `object_id` BIGINT UNSIGNED NOT NULL,
  `index` BIGINT UNSIGNED NOT NULL,
  `value` BIGINT UNSIGNED NULL,
  CONSTRAINT `Dna_entityReference_object_id_fk`
    FOREIGN KEY (`object_id`)
    REFERENCES `Dna` (`unipaxId`)
    ON DELETE CASCADE)
 ENGINE=InnoDB;

CREATE INDEX `object_id_i`
  ON `Dna_entityReference` (`object_id`);

CREATE INDEX `index_i`
  ON `Dna_entityReference` (`index`);

ALTER TABLE `Dna`
  ADD CONSTRAINT `Dna_unipaxId_fk`
    FOREIGN KEY (`unipaxId`)
    REFERENCES `PhysicalEntity` (`unipaxId`)
    ON DELETE CASCADE;

/*
ALTER TABLE `Dna_entityReference`
  ADD CONSTRAINT `Dna_entityReference_value_fk`
    FOREIGN KEY (`value`)
    REFERENCES `EntityReference` (`unipaxId`)
*/

