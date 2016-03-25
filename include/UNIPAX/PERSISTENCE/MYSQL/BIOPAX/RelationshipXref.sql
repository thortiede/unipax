/* This file was generated by ODB, object-relational mapping (ORM)
 * compiler for C++.
 */

DROP TABLE IF EXISTS `RelationshipXref_relationshipType`;

DROP TABLE IF EXISTS `RelationshipXref`;

CREATE TABLE `RelationshipXref` (
  `unipaxId` BIGINT UNSIGNED NOT NULL PRIMARY KEY)
 ENGINE=InnoDB;

CREATE TABLE `RelationshipXref_relationshipType` (
  `object_id` BIGINT UNSIGNED NOT NULL,
  `index` BIGINT UNSIGNED NOT NULL,
  `value` BIGINT UNSIGNED NULL,
  CONSTRAINT `RelationshipXref_relationshipType_object_id_fk`
    FOREIGN KEY (`object_id`)
    REFERENCES `RelationshipXref` (`unipaxId`)
    ON DELETE CASCADE)
 ENGINE=InnoDB;

CREATE INDEX `object_id_i`
  ON `RelationshipXref_relationshipType` (`object_id`);

CREATE INDEX `index_i`
  ON `RelationshipXref_relationshipType` (`index`);

ALTER TABLE `RelationshipXref`
  ADD CONSTRAINT `RelationshipXref_unipaxId_fk`
    FOREIGN KEY (`unipaxId`)
    REFERENCES `Xref` (`unipaxId`)
    ON DELETE CASCADE;

/*
ALTER TABLE `RelationshipXref_relationshipType`
  ADD CONSTRAINT `RelationshipXref_relationshipType_value_fk`
    FOREIGN KEY (`value`)
    REFERENCES `RelationshipTypeVocabulary` (`unipaxId`)
*/

