/* This file was generated by ODB, object-relational mapping (ORM)
 * compiler for C++.
 */

SET FEEDBACK OFF;
WHENEVER SQLERROR EXIT FAILURE;
WHENEVER OSERROR EXIT FAILURE;

BEGIN
  BEGIN
    EXECUTE IMMEDIATE 'DROP TABLE "Modulation_id_controller" CASCADE CONSTRAINTS';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -942 THEN RAISE; END IF;
  END;  BEGIN
    EXECUTE IMMEDIATE 'DROP SEQUENCE "Modulation_id_controller_seq"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -2289 THEN RAISE; END IF;
  END;
  BEGIN
    EXECUTE IMMEDIATE 'DROP TRIGGER "Modulation_id_controller_trg"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -4080 THEN RAISE; END IF;
  END;
END;
/

BEGIN
  BEGIN
    EXECUTE IMMEDIATE 'DROP TABLE "Modulation_interactionType" CASCADE CONSTRAINTS';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -942 THEN RAISE; END IF;
  END;  BEGIN
    EXECUTE IMMEDIATE 'DROP SEQUENCE "Modulation_interactionType_seq"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -2289 THEN RAISE; END IF;
  END;
  BEGIN
    EXECUTE IMMEDIATE 'DROP TRIGGER "Modulation_interactionType_trg"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -4080 THEN RAISE; END IF;
  END;
END;
/

BEGIN
  BEGIN
    EXECUTE IMMEDIATE 'DROP TABLE "Modulation_id_participant" CASCADE CONSTRAINTS';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -942 THEN RAISE; END IF;
  END;  BEGIN
    EXECUTE IMMEDIATE 'DROP SEQUENCE "Modulation_id_participant_seq"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -2289 THEN RAISE; END IF;
  END;
  BEGIN
    EXECUTE IMMEDIATE 'DROP TRIGGER "Modulation_id_participant_trg"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -4080 THEN RAISE; END IF;
  END;
END;
/

BEGIN
  BEGIN
    EXECUTE IMMEDIATE 'DROP TABLE "Modulation_id_xref" CASCADE CONSTRAINTS';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -942 THEN RAISE; END IF;
  END;  BEGIN
    EXECUTE IMMEDIATE 'DROP SEQUENCE "Modulation_id_xref_seq"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -2289 THEN RAISE; END IF;
  END;
  BEGIN
    EXECUTE IMMEDIATE 'DROP TRIGGER "Modulation_id_xref_trg"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -4080 THEN RAISE; END IF;
  END;
END;
/

BEGIN
  BEGIN
    EXECUTE IMMEDIATE 'DROP TABLE "Modulation_name" CASCADE CONSTRAINTS';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -942 THEN RAISE; END IF;
  END;  BEGIN
    EXECUTE IMMEDIATE 'DROP SEQUENCE "Modulation_name_seq"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -2289 THEN RAISE; END IF;
  END;
  BEGIN
    EXECUTE IMMEDIATE 'DROP TRIGGER "Modulation_name_trg"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -4080 THEN RAISE; END IF;
  END;
END;
/

BEGIN
  BEGIN
    EXECUTE IMMEDIATE 'DROP TABLE "Modulation_comments" CASCADE CONSTRAINTS';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -942 THEN RAISE; END IF;
  END;  BEGIN
    EXECUTE IMMEDIATE 'DROP SEQUENCE "Modulation_comments_seq"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -2289 THEN RAISE; END IF;
  END;
  BEGIN
    EXECUTE IMMEDIATE 'DROP TRIGGER "Modulation_comments_trg"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -4080 THEN RAISE; END IF;
  END;
END;
/

BEGIN
  BEGIN
    EXECUTE IMMEDIATE 'DROP TABLE "Modulation" CASCADE CONSTRAINTS';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -942 THEN RAISE; END IF;
  END;  BEGIN
    EXECUTE IMMEDIATE 'DROP SEQUENCE "Modulation_seq"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -2289 THEN RAISE; END IF;
  END;
  BEGIN
    EXECUTE IMMEDIATE 'DROP TRIGGER "Modulation_trg"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -4080 THEN RAISE; END IF;
  END;
END;
/


CREATE TABLE "Modulation" (
  "unipaxId" NUMBER(20) NOT NULL PRIMARY KEY,
  "unipaxSource" NUMBER(20),
  "availability" VARCHAR2(512),
  "standardName" VARCHAR2(512),
  "displayName" VARCHAR2(512),
  "evidence" NUMBER(20),
  "dataSource" NUMBER(20),
  "controlType" VARCHAR2(512),
  "id_controlled" NUMBER(20) NOT NULL);

CREATE TABLE "Modulation_comments" (
  "object_id" NUMBER(20) NOT NULL,
  "index" NUMBER(20) NOT NULL,
  "value" VARCHAR2(512),
  CONSTRAINT "Modulation_comments_object_id_"
    FOREIGN KEY ("object_id")
    REFERENCES "Modulation" ("unipaxId")
    ON DELETE CASCADE);

CREATE INDEX "Modulation_comments_object_id_"
  ON "Modulation_comments" ("object_id");

CREATE INDEX "Modulation_comments_index_i"
  ON "Modulation_comments" ("index");

CREATE TABLE "Modulation_name" (
  "object_id" NUMBER(20) NOT NULL,
  "index" NUMBER(20) NOT NULL,
  "value" VARCHAR2(512),
  CONSTRAINT "Modulation_name_object_id_fk"
    FOREIGN KEY ("object_id")
    REFERENCES "Modulation" ("unipaxId")
    ON DELETE CASCADE);

CREATE INDEX "Modulation_name_object_id_i"
  ON "Modulation_name" ("object_id");

CREATE INDEX "Modulation_name_index_i"
  ON "Modulation_name" ("index");

CREATE TABLE "Modulation_id_xref" (
  "object_id" NUMBER(20) NOT NULL,
  "index" NUMBER(20) NOT NULL,
  "value" NUMBER(20) NOT NULL,
  CONSTRAINT "Modulation_id_xref_object_id_f"
    FOREIGN KEY ("object_id")
    REFERENCES "Modulation" ("unipaxId")
    ON DELETE CASCADE);

CREATE INDEX "Modulation_id_xref_object_id_i"
  ON "Modulation_id_xref" ("object_id");

CREATE INDEX "Modulation_id_xref_index_i"
  ON "Modulation_id_xref" ("index");

CREATE TABLE "Modulation_id_participant" (
  "object_id" NUMBER(20) NOT NULL,
  "index" NUMBER(20) NOT NULL,
  "value" NUMBER(20) NOT NULL,
  CONSTRAINT "Modulation_id_participant_obje"
    FOREIGN KEY ("object_id")
    REFERENCES "Modulation" ("unipaxId")
    ON DELETE CASCADE);

CREATE INDEX "Modulation_id_participant_obje"
  ON "Modulation_id_participant" ("object_id");

CREATE INDEX "Modulation_id_participant_inde"
  ON "Modulation_id_participant" ("index");

CREATE TABLE "Modulation_interactionType" (
  "object_id" NUMBER(20) NOT NULL,
  "index" NUMBER(20) NOT NULL,
  "value" NUMBER(20),
  CONSTRAINT "Modulation_interactionType_obj"
    FOREIGN KEY ("object_id")
    REFERENCES "Modulation" ("unipaxId")
    ON DELETE CASCADE);

CREATE INDEX "Modulation_interactionType_obj"
  ON "Modulation_interactionType" ("object_id");

CREATE INDEX "Modulation_interactionType_ind"
  ON "Modulation_interactionType" ("index");

CREATE TABLE "Modulation_id_controller" (
  "object_id" NUMBER(20) NOT NULL,
  "index" NUMBER(20) NOT NULL,
  "value" NUMBER(20) NOT NULL,
  CONSTRAINT "Modulation_id_controller_objec"
    FOREIGN KEY ("object_id")
    REFERENCES "Modulation" ("unipaxId")
    ON DELETE CASCADE);

CREATE INDEX "Modulation_id_controller_objec"
  ON "Modulation_id_controller" ("object_id");

CREATE INDEX "Modulation_id_controller_index"
  ON "Modulation_id_controller" ("index");

ALTER TABLE "Modulation" ADD
  CONSTRAINT "Modulation_unipaxSource_fk"
    FOREIGN KEY ("unipaxSource")
    REFERENCES "ImportSource" ("unipaxId")
    DEFERRABLE INITIALLY DEFERRED;

ALTER TABLE "Modulation" ADD
  CONSTRAINT "Modulation_evidence_fk"
    FOREIGN KEY ("evidence")
    REFERENCES "Evidence" ("unipaxId")
    DEFERRABLE INITIALLY DEFERRED;

ALTER TABLE "Modulation" ADD
  CONSTRAINT "Modulation_dataSource_fk"
    FOREIGN KEY ("dataSource")
    REFERENCES "Provenance" ("unipaxId")
    DEFERRABLE INITIALLY DEFERRED;

ALTER TABLE "Modulation_interactionType" ADD
  CONSTRAINT "Modulation_interactionType_val"
    FOREIGN KEY ("value")
    REFERENCES "InteractionVocabulary" ("unipaxId")
    DEFERRABLE INITIALLY DEFERRED;

EXIT;
