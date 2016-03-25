/* This file was generated by ODB, object-relational mapping (ORM)
 * compiler for C++.
 */

DROP TABLE IF EXISTS `AssignmentRule`;

CREATE TABLE `AssignmentRule` (
  `unipaxId` BIGINT UNSIGNED NOT NULL PRIMARY KEY,
  `variable` TEXT NOT NULL)
 ENGINE=InnoDB;

ALTER TABLE `AssignmentRule`
  ADD CONSTRAINT `AssignmentRule_unipaxId_fk`
    FOREIGN KEY (`unipaxId`)
    REFERENCES `Rule` (`unipaxId`)
    ON DELETE CASCADE;

