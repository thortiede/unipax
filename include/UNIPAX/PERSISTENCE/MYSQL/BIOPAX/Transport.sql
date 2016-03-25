/* This file was generated by ODB, object-relational mapping (ORM)
 * compiler for C++.
 */

DROP TABLE IF EXISTS `Transport`;

CREATE TABLE `Transport` (
  `unipaxId` BIGINT UNSIGNED NOT NULL PRIMARY KEY)
 ENGINE=InnoDB;

ALTER TABLE `Transport`
  ADD CONSTRAINT `Transport_unipaxId_fk`
    FOREIGN KEY (`unipaxId`)
    REFERENCES `Conversion` (`unipaxId`)
    ON DELETE CASCADE;

