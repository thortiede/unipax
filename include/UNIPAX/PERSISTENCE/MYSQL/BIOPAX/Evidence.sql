/* This file was generated by ODB, object-relational mapping (ORM)
 * compiler for C++.
 */

DROP TABLE IF EXISTS `Evidence_xref`;

DROP TABLE IF EXISTS `Evidence_confidence`;

DROP TABLE IF EXISTS `Evidence_experimentalForm`;

DROP TABLE IF EXISTS `Evidence_evidenceCode`;

DROP TABLE IF EXISTS `Evidence_comment`;

DROP TABLE IF EXISTS `Evidence`;

CREATE TABLE `Evidence` (
  `unipaxId` BIGINT UNSIGNED NOT NULL PRIMARY KEY,
  `unipaxSource` BIGINT UNSIGNED NULL,
  `typeid` VARCHAR(255) NOT NULL)
 ENGINE=InnoDB;

CREATE TABLE `Evidence_comment` (
  `object_id` BIGINT UNSIGNED NOT NULL,
  `index` BIGINT UNSIGNED NOT NULL,
  `value` TEXT NOT NULL,
  CONSTRAINT `Evidence_comment_object_id_fk`
    FOREIGN KEY (`object_id`)
    REFERENCES `Evidence` (`unipaxId`)
    ON DELETE CASCADE)
 ENGINE=InnoDB;

CREATE INDEX `object_id_i`
  ON `Evidence_comment` (`object_id`);

CREATE INDEX `index_i`
  ON `Evidence_comment` (`index`);

CREATE TABLE `Evidence_evidenceCode` (
  `object_id` BIGINT UNSIGNED NOT NULL,
  `index` BIGINT UNSIGNED NOT NULL,
  `value` BIGINT UNSIGNED NULL,
  CONSTRAINT `Evidence_evidenceCode_object_id_fk`
    FOREIGN KEY (`object_id`)
    REFERENCES `Evidence` (`unipaxId`)
    ON DELETE CASCADE)
 ENGINE=InnoDB;

CREATE INDEX `object_id_i`
  ON `Evidence_evidenceCode` (`object_id`);

CREATE INDEX `index_i`
  ON `Evidence_evidenceCode` (`index`);

CREATE TABLE `Evidence_experimentalForm` (
  `object_id` BIGINT UNSIGNED NOT NULL,
  `index` BIGINT UNSIGNED NOT NULL,
  `value` BIGINT UNSIGNED NULL,
  CONSTRAINT `Evidence_experimentalForm_object_id_fk`
    FOREIGN KEY (`object_id`)
    REFERENCES `Evidence` (`unipaxId`)
    ON DELETE CASCADE)
 ENGINE=InnoDB;

CREATE INDEX `object_id_i`
  ON `Evidence_experimentalForm` (`object_id`);

CREATE INDEX `index_i`
  ON `Evidence_experimentalForm` (`index`);

CREATE TABLE `Evidence_confidence` (
  `object_id` BIGINT UNSIGNED NOT NULL,
  `index` BIGINT UNSIGNED NOT NULL,
  `value` BIGINT UNSIGNED NULL,
  CONSTRAINT `Evidence_confidence_object_id_fk`
    FOREIGN KEY (`object_id`)
    REFERENCES `Evidence` (`unipaxId`)
    ON DELETE CASCADE)
 ENGINE=InnoDB;

CREATE INDEX `object_id_i`
  ON `Evidence_confidence` (`object_id`);

CREATE INDEX `index_i`
  ON `Evidence_confidence` (`index`);

CREATE TABLE `Evidence_xref` (
  `object_id` BIGINT UNSIGNED NOT NULL,
  `index` BIGINT UNSIGNED NOT NULL,
  `value` BIGINT UNSIGNED NULL,
  CONSTRAINT `Evidence_xref_object_id_fk`
    FOREIGN KEY (`object_id`)
    REFERENCES `Evidence` (`unipaxId`)
    ON DELETE CASCADE)
 ENGINE=InnoDB;

CREATE INDEX `object_id_i`
  ON `Evidence_xref` (`object_id`);

CREATE INDEX `index_i`
  ON `Evidence_xref` (`index`);

/*
ALTER TABLE `Evidence`
  ADD CONSTRAINT `Evidence_unipaxSource_fk`
    FOREIGN KEY (`unipaxSource`)
    REFERENCES `ImportSource` (`unipaxId`)
*/

/*
ALTER TABLE `Evidence_evidenceCode`
  ADD CONSTRAINT `Evidence_evidenceCode_value_fk`
    FOREIGN KEY (`value`)
    REFERENCES `EvidenceCodeVocabulary` (`unipaxId`)
*/

/*
ALTER TABLE `Evidence_experimentalForm`
  ADD CONSTRAINT `Evidence_experimentalForm_value_fk`
    FOREIGN KEY (`value`)
    REFERENCES `ExperimentalForm` (`unipaxId`)
*/

/*
ALTER TABLE `Evidence_confidence`
  ADD CONSTRAINT `Evidence_confidence_value_fk`
    FOREIGN KEY (`value`)
    REFERENCES `Score` (`unipaxId`)
*/

/*
ALTER TABLE `Evidence_xref`
  ADD CONSTRAINT `Evidence_xref_value_fk`
    FOREIGN KEY (`value`)
    REFERENCES `Xref` (`unipaxId`)
*/

