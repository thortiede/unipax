/* This file was generated by ODB, object-relational mapping (ORM)
 * compiler for C++.
 */

SET FEEDBACK OFF;
WHENEVER SQLERROR EXIT FAILURE;
WHENEVER OSERROR EXIT FAILURE;

BEGIN
  BEGIN
    EXECUTE IMMEDIATE 'DROP TABLE "DnaRegion_id_entityReference" CASCADE CONSTRAINTS';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -942 THEN RAISE; END IF;
  END;  BEGIN
    EXECUTE IMMEDIATE 'DROP SEQUENCE "DnaRegion_id_entityReference_s"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -2289 THEN RAISE; END IF;
  END;
  BEGIN
    EXECUTE IMMEDIATE 'DROP TRIGGER "DnaRegion_id_entityReference_t"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -4080 THEN RAISE; END IF;
  END;
END;
/

BEGIN
  BEGIN
    EXECUTE IMMEDIATE 'DROP TABLE "DnaRegion_id_notFeature" CASCADE CONSTRAINTS';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -942 THEN RAISE; END IF;
  END;  BEGIN
    EXECUTE IMMEDIATE 'DROP SEQUENCE "DnaRegion_id_notFeature_seq"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -2289 THEN RAISE; END IF;
  END;
  BEGIN
    EXECUTE IMMEDIATE 'DROP TRIGGER "DnaRegion_id_notFeature_trg"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -4080 THEN RAISE; END IF;
  END;
END;
/

BEGIN
  BEGIN
    EXECUTE IMMEDIATE 'DROP TABLE "DnaRegion_id_memberPhysicalEnt" CASCADE CONSTRAINTS';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -942 THEN RAISE; END IF;
  END;  BEGIN
    EXECUTE IMMEDIATE 'DROP SEQUENCE "DnaRegion_id_memberPhysicalEnt"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -2289 THEN RAISE; END IF;
  END;
  BEGIN
    EXECUTE IMMEDIATE 'DROP TRIGGER "DnaRegion_id_memberPhysicalEnt"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -4080 THEN RAISE; END IF;
  END;
END;
/

BEGIN
  BEGIN
    EXECUTE IMMEDIATE 'DROP TABLE "DnaRegion_id_feature" CASCADE CONSTRAINTS';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -942 THEN RAISE; END IF;
  END;  BEGIN
    EXECUTE IMMEDIATE 'DROP SEQUENCE "DnaRegion_id_feature_seq"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -2289 THEN RAISE; END IF;
  END;
  BEGIN
    EXECUTE IMMEDIATE 'DROP TRIGGER "DnaRegion_id_feature_trg"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -4080 THEN RAISE; END IF;
  END;
END;
/

BEGIN
  BEGIN
    EXECUTE IMMEDIATE 'DROP TABLE "DnaRegion_id_xref" CASCADE CONSTRAINTS';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -942 THEN RAISE; END IF;
  END;  BEGIN
    EXECUTE IMMEDIATE 'DROP SEQUENCE "DnaRegion_id_xref_seq"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -2289 THEN RAISE; END IF;
  END;
  BEGIN
    EXECUTE IMMEDIATE 'DROP TRIGGER "DnaRegion_id_xref_trg"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -4080 THEN RAISE; END IF;
  END;
END;
/

BEGIN
  BEGIN
    EXECUTE IMMEDIATE 'DROP TABLE "DnaRegion_name" CASCADE CONSTRAINTS';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -942 THEN RAISE; END IF;
  END;  BEGIN
    EXECUTE IMMEDIATE 'DROP SEQUENCE "DnaRegion_name_seq"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -2289 THEN RAISE; END IF;
  END;
  BEGIN
    EXECUTE IMMEDIATE 'DROP TRIGGER "DnaRegion_name_trg"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -4080 THEN RAISE; END IF;
  END;
END;
/

BEGIN
  BEGIN
    EXECUTE IMMEDIATE 'DROP TABLE "DnaRegion_comments" CASCADE CONSTRAINTS';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -942 THEN RAISE; END IF;
  END;  BEGIN
    EXECUTE IMMEDIATE 'DROP SEQUENCE "DnaRegion_comments_seq"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -2289 THEN RAISE; END IF;
  END;
  BEGIN
    EXECUTE IMMEDIATE 'DROP TRIGGER "DnaRegion_comments_trg"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -4080 THEN RAISE; END IF;
  END;
END;
/

BEGIN
  BEGIN
    EXECUTE IMMEDIATE 'DROP TABLE "DnaRegion" CASCADE CONSTRAINTS';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -942 THEN RAISE; END IF;
  END;  BEGIN
    EXECUTE IMMEDIATE 'DROP SEQUENCE "DnaRegion_seq"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -2289 THEN RAISE; END IF;
  END;
  BEGIN
    EXECUTE IMMEDIATE 'DROP TRIGGER "DnaRegion_trg"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -4080 THEN RAISE; END IF;
  END;
END;
/


CREATE TABLE "DnaRegion" (
  "unipaxId" NUMBER(20) NOT NULL PRIMARY KEY,
  "unipaxSource" NUMBER(20),
  "availability" VARCHAR2(512),
  "standardName" VARCHAR2(512),
  "displayName" VARCHAR2(512),
  "evidence" NUMBER(20),
  "dataSource" NUMBER(20),
  "cellularLocation" NUMBER(20));

CREATE TABLE "DnaRegion_comments" (
  "object_id" NUMBER(20) NOT NULL,
  "index" NUMBER(20) NOT NULL,
  "value" VARCHAR2(512),
  CONSTRAINT "DnaRegion_comments_object_id_f"
    FOREIGN KEY ("object_id")
    REFERENCES "DnaRegion" ("unipaxId")
    ON DELETE CASCADE);

CREATE INDEX "DnaRegion_comments_object_id_i"
  ON "DnaRegion_comments" ("object_id");

CREATE INDEX "DnaRegion_comments_index_i"
  ON "DnaRegion_comments" ("index");

CREATE TABLE "DnaRegion_name" (
  "object_id" NUMBER(20) NOT NULL,
  "index" NUMBER(20) NOT NULL,
  "value" VARCHAR2(512),
  CONSTRAINT "DnaRegion_name_object_id_fk"
    FOREIGN KEY ("object_id")
    REFERENCES "DnaRegion" ("unipaxId")
    ON DELETE CASCADE);

CREATE INDEX "DnaRegion_name_object_id_i"
  ON "DnaRegion_name" ("object_id");

CREATE INDEX "DnaRegion_name_index_i"
  ON "DnaRegion_name" ("index");

CREATE TABLE "DnaRegion_id_xref" (
  "object_id" NUMBER(20) NOT NULL,
  "index" NUMBER(20) NOT NULL,
  "value" NUMBER(20) NOT NULL,
  CONSTRAINT "DnaRegion_id_xref_object_id_fk"
    FOREIGN KEY ("object_id")
    REFERENCES "DnaRegion" ("unipaxId")
    ON DELETE CASCADE);

CREATE INDEX "DnaRegion_id_xref_object_id_i"
  ON "DnaRegion_id_xref" ("object_id");

CREATE INDEX "DnaRegion_id_xref_index_i"
  ON "DnaRegion_id_xref" ("index");

CREATE TABLE "DnaRegion_id_feature" (
  "object_id" NUMBER(20) NOT NULL,
  "index" NUMBER(20) NOT NULL,
  "value" NUMBER(20) NOT NULL,
  CONSTRAINT "DnaRegion_id_feature_object_id"
    FOREIGN KEY ("object_id")
    REFERENCES "DnaRegion" ("unipaxId")
    ON DELETE CASCADE);

CREATE INDEX "DnaRegion_id_feature_object_id"
  ON "DnaRegion_id_feature" ("object_id");

CREATE INDEX "DnaRegion_id_feature_index_i"
  ON "DnaRegion_id_feature" ("index");

CREATE TABLE "DnaRegion_id_memberPhysicalEnt" (
  "object_id" NUMBER(20) NOT NULL,
  "index" NUMBER(20) NOT NULL,
  "value" NUMBER(20) NOT NULL,
  CONSTRAINT "DnaRegion_id_memberPhysicalEnt"
    FOREIGN KEY ("object_id")
    REFERENCES "DnaRegion" ("unipaxId")
    ON DELETE CASCADE);

CREATE INDEX "DnaRegion_id_memberPhysicalEnt"
  ON "DnaRegion_id_memberPhysicalEnt" ("object_id");

CREATE INDEX "DnaRegion_id_memberPhysicalEnt"
  ON "DnaRegion_id_memberPhysicalEnt" ("index");

CREATE TABLE "DnaRegion_id_notFeature" (
  "object_id" NUMBER(20) NOT NULL,
  "index" NUMBER(20) NOT NULL,
  "value" NUMBER(20) NOT NULL,
  CONSTRAINT "DnaRegion_id_notFeature_object"
    FOREIGN KEY ("object_id")
    REFERENCES "DnaRegion" ("unipaxId")
    ON DELETE CASCADE);

CREATE INDEX "DnaRegion_id_notFeature_object"
  ON "DnaRegion_id_notFeature" ("object_id");

CREATE INDEX "DnaRegion_id_notFeature_index_"
  ON "DnaRegion_id_notFeature" ("index");

CREATE TABLE "DnaRegion_id_entityReference" (
  "object_id" NUMBER(20) NOT NULL,
  "index" NUMBER(20) NOT NULL,
  "value" NUMBER(20) NOT NULL,
  CONSTRAINT "DnaRegion_id_entityReference_o"
    FOREIGN KEY ("object_id")
    REFERENCES "DnaRegion" ("unipaxId")
    ON DELETE CASCADE);

CREATE INDEX "DnaRegion_id_entityReference_o"
  ON "DnaRegion_id_entityReference" ("object_id");

CREATE INDEX "DnaRegion_id_entityReference_i"
  ON "DnaRegion_id_entityReference" ("index");

ALTER TABLE "DnaRegion" ADD
  CONSTRAINT "DnaRegion_unipaxSource_fk"
    FOREIGN KEY ("unipaxSource")
    REFERENCES "ImportSource" ("unipaxId")
    DEFERRABLE INITIALLY DEFERRED;

ALTER TABLE "DnaRegion" ADD
  CONSTRAINT "DnaRegion_evidence_fk"
    FOREIGN KEY ("evidence")
    REFERENCES "Evidence" ("unipaxId")
    DEFERRABLE INITIALLY DEFERRED;

ALTER TABLE "DnaRegion" ADD
  CONSTRAINT "DnaRegion_dataSource_fk"
    FOREIGN KEY ("dataSource")
    REFERENCES "Provenance" ("unipaxId")
    DEFERRABLE INITIALLY DEFERRED;

ALTER TABLE "DnaRegion" ADD
  CONSTRAINT "DnaRegion_cellularLocation_fk"
    FOREIGN KEY ("cellularLocation")
    REFERENCES "CellularLocationVocabulary" ("unipaxId")
    DEFERRABLE INITIALLY DEFERRED;

EXIT;
