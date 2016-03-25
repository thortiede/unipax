/* This file was generated by ODB, object-relational mapping (ORM)
 * compiler for C++.
 */

SET FEEDBACK OFF;
WHENEVER SQLERROR EXIT FAILURE;
WHENEVER OSERROR EXIT FAILURE;

BEGIN
  BEGIN
    EXECUTE IMMEDIATE 'DROP TABLE "RelationshipTypeVocabulary_id_xref" CASCADE CONSTRAINTS';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -942 THEN RAISE; END IF;
  END;  BEGIN
    EXECUTE IMMEDIATE 'DROP SEQUENCE "RelationshipTypeVocabulary_id_xref_se"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -2289 THEN RAISE; END IF;
  END;
  BEGIN
    EXECUTE IMMEDIATE 'DROP TRIGGER "RelationshipTypeVocabulary_id_xref_tr"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -4080 THEN RAISE; END IF;
  END;
END;
/

BEGIN
  BEGIN
    EXECUTE IMMEDIATE 'DROP TABLE "RelationshipTypeVocabulary_comment" CASCADE CONSTRAINTS';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -942 THEN RAISE; END IF;
  END;  BEGIN
    EXECUTE IMMEDIATE 'DROP SEQUENCE "RelationshipTypeVocabulary_comment_se"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -2289 THEN RAISE; END IF;
  END;
  BEGIN
    EXECUTE IMMEDIATE 'DROP TRIGGER "RelationshipTypeVocabulary_comment_tr"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -4080 THEN RAISE; END IF;
  END;
END;
/

BEGIN
  BEGIN
    EXECUTE IMMEDIATE 'DROP TABLE "RelationshipTypeVocabulary" CASCADE CONSTRAINTS';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -942 THEN RAISE; END IF;
  END;  BEGIN
    EXECUTE IMMEDIATE 'DROP SEQUENCE "RelationshipTypeVocabulary_seq"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -2289 THEN RAISE; END IF;
  END;
  BEGIN
    EXECUTE IMMEDIATE 'DROP TRIGGER "RelationshipTypeVocabulary_trg"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -4080 THEN RAISE; END IF;
  END;
END;
/


CREATE TABLE "RelationshipTypeVocabulary" (
  "unipaxId" NUMBER(20) NOT NULL PRIMARY KEY,
  "unipaxSource" NUMBER(20),
  "term" VARCHAR2(512));

CREATE TABLE "RelationshipTypeVocabulary_comment" (
  "object_id" NUMBER(20) NOT NULL,
  "index" NUMBER(20) NOT NULL,
  "value" VARCHAR2(512),
  CONSTRAINT "RelationshipTypeVocabulary_comment_ob"
    FOREIGN KEY ("object_id")
    REFERENCES "RelationshipTypeVocabulary" ("unipaxId")
    ON DELETE CASCADE);

CREATE INDEX "RelationshipTypeVocabulary_comment_ob"
  ON "RelationshipTypeVocabulary_comment" ("object_id");

CREATE INDEX "RelationshipTypeVocabulary_comment_in"
  ON "RelationshipTypeVocabulary_comment" ("index");

CREATE TABLE "RelationshipTypeVocabulary_id_xref" (
  "object_id" NUMBER(20) NOT NULL,
  "index" NUMBER(20) NOT NULL,
  "value" NUMBER(20) NOT NULL,
  CONSTRAINT "RelationshipTypeVocabulary_id_xref_ob"
    FOREIGN KEY ("object_id")
    REFERENCES "RelationshipTypeVocabulary" ("unipaxId")
    ON DELETE CASCADE);

CREATE INDEX "RelationshipTypeVocabulary_id_xref_ob"
  ON "RelationshipTypeVocabulary_id_xref" ("object_id");

CREATE INDEX "RelationshipTypeVocabulary_id_xref_in"
  ON "RelationshipTypeVocabulary_id_xref" ("index");

ALTER TABLE "RelationshipTypeVocabulary" ADD
  CONSTRAINT "RelationshipTypeVocabulary_unipaxSour"
    FOREIGN KEY ("unipaxSource")
    REFERENCES "ImportSource" ("unipaxId")
    DEFERRABLE INITIALLY DEFERRED;

EXIT;
