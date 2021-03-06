/* This file was generated by ODB, object-relational mapping (ORM)
 * compiler for C++.
 */

DROP TABLE IF EXISTS `Series_xref`;

DROP TABLE IF EXISTS `Series_sample_list`;

DROP TABLE IF EXISTS `Series_idMapping_list`;

DROP TABLE IF EXISTS `Series_description_tags`;

DROP TABLE IF EXISTS `Series`;

CREATE TABLE `Series` (
  `unipaxId` BIGINT UNSIGNED NOT NULL PRIMARY KEY,
  `unipaxSource` BIGINT UNSIGNED NULL,
  `name` TEXT NOT NULL,
  `description` TEXT NOT NULL)
 ENGINE=InnoDB;

CREATE TABLE `Series_description_tags` (
  `object_id` BIGINT UNSIGNED NOT NULL,
  `key` TEXT NOT NULL,
  `value` TEXT NOT NULL,
  CONSTRAINT `Series_description_tags_object_id_fk`
    FOREIGN KEY (`object_id`)
    REFERENCES `Series` (`unipaxId`)
    ON DELETE CASCADE)
 ENGINE=InnoDB;

CREATE INDEX `object_id_i`
  ON `Series_description_tags` (`object_id`);

CREATE TABLE `Series_idMapping_list` (
  `object_id` BIGINT UNSIGNED NOT NULL,
  `index` BIGINT UNSIGNED NOT NULL,
  `value` BIGINT UNSIGNED NULL,
  CONSTRAINT `Series_idMapping_list_object_id_fk`
    FOREIGN KEY (`object_id`)
    REFERENCES `Series` (`unipaxId`)
    ON DELETE CASCADE)
 ENGINE=InnoDB;

CREATE INDEX `object_id_i`
  ON `Series_idMapping_list` (`object_id`);

CREATE INDEX `index_i`
  ON `Series_idMapping_list` (`index`);

CREATE TABLE `Series_sample_list` (
  `object_id` BIGINT UNSIGNED NOT NULL,
  `index` BIGINT UNSIGNED NOT NULL,
  `value` BIGINT UNSIGNED NULL,
  CONSTRAINT `Series_sample_list_object_id_fk`
    FOREIGN KEY (`object_id`)
    REFERENCES `Series` (`unipaxId`)
    ON DELETE CASCADE)
 ENGINE=InnoDB;

CREATE INDEX `object_id_i`
  ON `Series_sample_list` (`object_id`);

CREATE INDEX `index_i`
  ON `Series_sample_list` (`index`);

CREATE TABLE `Series_xref` (
  `object_id` BIGINT UNSIGNED NOT NULL,
  `index` BIGINT UNSIGNED NOT NULL,
  `value` BIGINT UNSIGNED NULL,
  CONSTRAINT `Series_xref_object_id_fk`
    FOREIGN KEY (`object_id`)
    REFERENCES `Series` (`unipaxId`)
    ON DELETE CASCADE)
 ENGINE=InnoDB;

CREATE INDEX `object_id_i`
  ON `Series_xref` (`object_id`);

CREATE INDEX `index_i`
  ON `Series_xref` (`index`);

/*
ALTER TABLE `Series`
  ADD CONSTRAINT `Series_unipaxSource_fk`
    FOREIGN KEY (`unipaxSource`)
    REFERENCES `ImportSource` (`unipaxId`)
*/

/*
ALTER TABLE `Series_idMapping_list`
  ADD CONSTRAINT `Series_idMapping_list_value_fk`
    FOREIGN KEY (`value`)
    REFERENCES `IdMapping` (`unipaxId`)
*/

/*
ALTER TABLE `Series_sample_list`
  ADD CONSTRAINT `Series_sample_list_value_fk`
    FOREIGN KEY (`value`)
    REFERENCES `Sample` (`unipaxId`)
*/

/*
ALTER TABLE `Series_xref`
  ADD CONSTRAINT `Series_xref_value_fk`
    FOREIGN KEY (`value`)
    REFERENCES `Xref` (`unipaxId`)
*/

