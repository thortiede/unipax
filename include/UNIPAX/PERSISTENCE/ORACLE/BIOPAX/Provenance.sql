/* This file was generated by ODB, object-relational mapping (ORM)
 * compiler for C++.
 */

SET FEEDBACK OFF;
WHENEVER SQLERROR EXIT FAILURE;
WHENEVER OSERROR EXIT FAILURE;

BEGIN
  BEGIN
    EXECUTE IMMEDIATE 'DROP TABLE "Provenance_name" CASCADE CONSTRAINTS';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -942 THEN RAISE; END IF;
  END;  BEGIN
    EXECUTE IMMEDIATE 'DROP SEQUENCE "Provenance_name_seq"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -2289 THEN RAISE; END IF;
  END;
  BEGIN
    EXECUTE IMMEDIATE 'DROP TRIGGER "Provenance_name_trg"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -4080 THEN RAISE; END IF;
  END;
END;
/

BEGIN
  BEGIN
    EXECUTE IMMEDIATE 'DROP TABLE "Provenance_id_xref" CASCADE CONSTRAINTS';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -942 THEN RAISE; END IF;
  END;  BEGIN
    EXECUTE IMMEDIATE 'DROP SEQUENCE "Provenance_id_xref_seq"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -2289 THEN RAISE; END IF;
  END;
  BEGIN
    EXECUTE IMMEDIATE 'DROP TRIGGER "Provenance_id_xref_trg"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -4080 THEN RAISE; END IF;
  END;
END;
/

BEGIN
  BEGIN
    EXECUTE IMMEDIATE 'DROP TABLE "Provenance_comment" CASCADE CONSTRAINTS';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -942 THEN RAISE; END IF;
  END;  BEGIN
    EXECUTE IMMEDIATE 'DROP SEQUENCE "Provenance_comment_seq"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -2289 THEN RAISE; END IF;
  END;
  BEGIN
    EXECUTE IMMEDIATE 'DROP TRIGGER "Provenance_comment_trg"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -4080 THEN RAISE; END IF;
  END;
END;
/

BEGIN
  BEGIN
    EXECUTE IMMEDIATE 'DROP TABLE "Provenance" CASCADE CONSTRAINTS';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -942 THEN RAISE; END IF;
  END;  BEGIN
    EXECUTE IMMEDIATE 'DROP SEQUENCE "Provenance_seq"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -2289 THEN RAISE; END IF;
  END;
  BEGIN
    EXECUTE IMMEDIATE 'DROP TRIGGER "Provenance_trg"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -4080 THEN RAISE; END IF;
  END;
END;
/


CREATE TABLE "Provenance" (
  "unipaxId" NUMBER(20) NOT NULL PRIMARY KEY,
  "unipaxSource" NUMBER(20),
  "standardName" VARCHAR2(512),
  "displayName" VARCHAR2(512));

CREATE TABLE "Provenance_comment" (
  "object_id" NUMBER(20) NOT NULL,
  "index" NUMBER(20) NOT NULL,
  "value" VARCHAR2(512),
  CONSTRAINT "Provenance_comment_object_id_f"
    FOREIGN KEY ("object_id")
    REFERENCES "Provenance" ("unipaxId")
    ON DELETE CASCADE);

CREATE INDEX "Provenance_comment_object_id_i"
  ON "Provenance_comment" ("object_id");

CREATE INDEX "Provenance_comment_index_i"
  ON "Provenance_comment" ("index");

CREATE TABLE "Provenance_id_xref" (
  "object_id" NUMBER(20) NOT NULL,
  "index" NUMBER(20) NOT NULL,
  "value" NUMBER(20) NOT NULL,
  CONSTRAINT "Provenance_id_xref_object_id_f"
    FOREIGN KEY ("object_id")
    REFERENCES "Provenance" ("unipaxId")
    ON DELETE CASCADE);

CREATE INDEX "Provenance_id_xref_object_id_i"
  ON "Provenance_id_xref" ("object_id");

CREATE INDEX "Provenance_id_xref_index_i"
  ON "Provenance_id_xref" ("index");

CREATE TABLE "Provenance_name" (
  "object_id" NUMBER(20) NOT NULL,
  "index" NUMBER(20) NOT NULL,
  "value" VARCHAR2(512),
  CONSTRAINT "Provenance_name_object_id_fk"
    FOREIGN KEY ("object_id")
    REFERENCES "Provenance" ("unipaxId")
    ON DELETE CASCADE);

CREATE INDEX "Provenance_name_object_id_i"
  ON "Provenance_name" ("object_id");

CREATE INDEX "Provenance_name_index_i"
  ON "Provenance_name" ("index");

ALTER TABLE "Provenance" ADD
  CONSTRAINT "Provenance_unipaxSource_fk"
    FOREIGN KEY ("unipaxSource")
    REFERENCES "ImportSource" ("unipaxId")
    DEFERRABLE INITIALLY DEFERRED;

EXIT;
