/* This file was generated by ODB, object-relational mapping (ORM)
 * compiler for C++.
 */

DROP TABLE IF EXISTS `GeneticInteraction_score`;

DROP TABLE IF EXISTS `GeneticInteraction_phenotype`;

DROP TABLE IF EXISTS `GeneticInteraction`;

CREATE TABLE `GeneticInteraction` (
  `unipaxId` BIGINT UNSIGNED NOT NULL PRIMARY KEY)
 ENGINE=InnoDB;

CREATE TABLE `GeneticInteraction_phenotype` (
  `object_id` BIGINT UNSIGNED NOT NULL,
  `index` BIGINT UNSIGNED NOT NULL,
  `value` BIGINT UNSIGNED NULL,
  CONSTRAINT `GeneticInteraction_phenotype_object_id_fk`
    FOREIGN KEY (`object_id`)
    REFERENCES `GeneticInteraction` (`unipaxId`)
    ON DELETE CASCADE)
 ENGINE=InnoDB;

CREATE INDEX `object_id_i`
  ON `GeneticInteraction_phenotype` (`object_id`);

CREATE INDEX `index_i`
  ON `GeneticInteraction_phenotype` (`index`);

CREATE TABLE `GeneticInteraction_score` (
  `object_id` BIGINT UNSIGNED NOT NULL,
  `index` BIGINT UNSIGNED NOT NULL,
  `value` BIGINT UNSIGNED NULL,
  CONSTRAINT `GeneticInteraction_score_object_id_fk`
    FOREIGN KEY (`object_id`)
    REFERENCES `GeneticInteraction` (`unipaxId`)
    ON DELETE CASCADE)
 ENGINE=InnoDB;

CREATE INDEX `object_id_i`
  ON `GeneticInteraction_score` (`object_id`);

CREATE INDEX `index_i`
  ON `GeneticInteraction_score` (`index`);

ALTER TABLE `GeneticInteraction`
  ADD CONSTRAINT `GeneticInteraction_unipaxId_fk`
    FOREIGN KEY (`unipaxId`)
    REFERENCES `Interaction` (`unipaxId`)
    ON DELETE CASCADE;

/*
ALTER TABLE `GeneticInteraction_phenotype`
  ADD CONSTRAINT `GeneticInteraction_phenotype_value_fk`
    FOREIGN KEY (`value`)
    REFERENCES `PhenotypeVocabulary` (`unipaxId`)
*/

/*
ALTER TABLE `GeneticInteraction_score`
  ADD CONSTRAINT `GeneticInteraction_score_value_fk`
    FOREIGN KEY (`value`)
    REFERENCES `Score` (`unipaxId`)
*/

