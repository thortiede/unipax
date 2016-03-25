/* This file was generated by ODB, object-relational mapping (ORM)
 * compiler for C++.
 */

SET FEEDBACK OFF;
WHENEVER SQLERROR EXIT FAILURE;
WHENEVER OSERROR EXIT FAILURE;

BEGIN
  BEGIN
    EXECUTE IMMEDIATE 'DROP TABLE "BindingFeature_id_bindsTo" CASCADE CONSTRAINTS';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -942 THEN RAISE; END IF;
  END;  BEGIN
    EXECUTE IMMEDIATE 'DROP SEQUENCE "BindingFeature_id_bindsTo_seq"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -2289 THEN RAISE; END IF;
  END;
  BEGIN
    EXECUTE IMMEDIATE 'DROP TRIGGER "BindingFeature_id_bindsTo_trg"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -4080 THEN RAISE; END IF;
  END;
END;
/

BEGIN
  BEGIN
    EXECUTE IMMEDIATE 'DROP TABLE "BindingFeature_featureLocation" CASCADE CONSTRAINTS';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -942 THEN RAISE; END IF;
  END;  BEGIN
    EXECUTE IMMEDIATE 'DROP SEQUENCE "BindingFeature_featureLocation"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -2289 THEN RAISE; END IF;
  END;
  BEGIN
    EXECUTE IMMEDIATE 'DROP TRIGGER "BindingFeature_featureLocation"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -4080 THEN RAISE; END IF;
  END;
END;
/

BEGIN
  BEGIN
    EXECUTE IMMEDIATE 'DROP TABLE "BindingFeature_id_featureLocat" CASCADE CONSTRAINTS';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -942 THEN RAISE; END IF;
  END;  BEGIN
    EXECUTE IMMEDIATE 'DROP SEQUENCE "BindingFeature_id_featureLocat"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -2289 THEN RAISE; END IF;
  END;
  BEGIN
    EXECUTE IMMEDIATE 'DROP TRIGGER "BindingFeature_id_featureLocat"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -4080 THEN RAISE; END IF;
  END;
END;
/

BEGIN
  BEGIN
    EXECUTE IMMEDIATE 'DROP TABLE "BindingFeature_id_memberFeatur" CASCADE CONSTRAINTS';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -942 THEN RAISE; END IF;
  END;  BEGIN
    EXECUTE IMMEDIATE 'DROP SEQUENCE "BindingFeature_id_memberFeatur"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -2289 THEN RAISE; END IF;
  END;
  BEGIN
    EXECUTE IMMEDIATE 'DROP TRIGGER "BindingFeature_id_memberFeatur"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -4080 THEN RAISE; END IF;
  END;
END;
/

BEGIN
  BEGIN
    EXECUTE IMMEDIATE 'DROP TABLE "BindingFeature_evidence" CASCADE CONSTRAINTS';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -942 THEN RAISE; END IF;
  END;  BEGIN
    EXECUTE IMMEDIATE 'DROP SEQUENCE "BindingFeature_evidence_seq"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -2289 THEN RAISE; END IF;
  END;
  BEGIN
    EXECUTE IMMEDIATE 'DROP TRIGGER "BindingFeature_evidence_trg"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -4080 THEN RAISE; END IF;
  END;
END;
/

BEGIN
  BEGIN
    EXECUTE IMMEDIATE 'DROP TABLE "BindingFeature_comment" CASCADE CONSTRAINTS';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -942 THEN RAISE; END IF;
  END;  BEGIN
    EXECUTE IMMEDIATE 'DROP SEQUENCE "BindingFeature_comment_seq"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -2289 THEN RAISE; END IF;
  END;
  BEGIN
    EXECUTE IMMEDIATE 'DROP TRIGGER "BindingFeature_comment_trg"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -4080 THEN RAISE; END IF;
  END;
END;
/

BEGIN
  BEGIN
    EXECUTE IMMEDIATE 'DROP TABLE "BindingFeature" CASCADE CONSTRAINTS';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -942 THEN RAISE; END IF;
  END;  BEGIN
    EXECUTE IMMEDIATE 'DROP SEQUENCE "BindingFeature_seq"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -2289 THEN RAISE; END IF;
  END;
  BEGIN
    EXECUTE IMMEDIATE 'DROP TRIGGER "BindingFeature_trg"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -4080 THEN RAISE; END IF;
  END;
END;
/


CREATE TABLE "BindingFeature" (
  "unipaxId" NUMBER(20) NOT NULL PRIMARY KEY,
  "unipaxSource" NUMBER(20),
  "intraMolecular" NUMBER(1) NOT NULL);

CREATE TABLE "BindingFeature_comment" (
  "object_id" NUMBER(20) NOT NULL,
  "index" NUMBER(20) NOT NULL,
  "value" VARCHAR2(512),
  CONSTRAINT "BindingFeature_comment_object_"
    FOREIGN KEY ("object_id")
    REFERENCES "BindingFeature" ("unipaxId")
    ON DELETE CASCADE);

CREATE INDEX "BindingFeature_comment_object_"
  ON "BindingFeature_comment" ("object_id");

CREATE INDEX "BindingFeature_comment_index_i"
  ON "BindingFeature_comment" ("index");

CREATE TABLE "BindingFeature_evidence" (
  "object_id" NUMBER(20) NOT NULL,
  "index" NUMBER(20) NOT NULL,
  "value" NUMBER(20),
  CONSTRAINT "BindingFeature_evidence_object"
    FOREIGN KEY ("object_id")
    REFERENCES "BindingFeature" ("unipaxId")
    ON DELETE CASCADE);

CREATE INDEX "BindingFeature_evidence_object"
  ON "BindingFeature_evidence" ("object_id");

CREATE INDEX "BindingFeature_evidence_index_"
  ON "BindingFeature_evidence" ("index");

CREATE TABLE "BindingFeature_id_memberFeatur" (
  "object_id" NUMBER(20) NOT NULL,
  "index" NUMBER(20) NOT NULL,
  "value" NUMBER(20) NOT NULL,
  CONSTRAINT "BindingFeature_id_memberFeatur"
    FOREIGN KEY ("object_id")
    REFERENCES "BindingFeature" ("unipaxId")
    ON DELETE CASCADE);

CREATE INDEX "BindingFeature_id_memberFeatur"
  ON "BindingFeature_id_memberFeatur" ("object_id");

CREATE INDEX "BindingFeature_id_memberFeatur"
  ON "BindingFeature_id_memberFeatur" ("index");

CREATE TABLE "BindingFeature_id_featureLocat" (
  "object_id" NUMBER(20) NOT NULL,
  "index" NUMBER(20) NOT NULL,
  "value" NUMBER(20) NOT NULL,
  CONSTRAINT "BindingFeature_id_featureLocat"
    FOREIGN KEY ("object_id")
    REFERENCES "BindingFeature" ("unipaxId")
    ON DELETE CASCADE);

CREATE INDEX "BindingFeature_id_featureLocat"
  ON "BindingFeature_id_featureLocat" ("object_id");

CREATE INDEX "BindingFeature_id_featureLocat"
  ON "BindingFeature_id_featureLocat" ("index");

CREATE TABLE "BindingFeature_featureLocation" (
  "object_id" NUMBER(20) NOT NULL,
  "index" NUMBER(20) NOT NULL,
  "value" NUMBER(20),
  CONSTRAINT "BindingFeature_featureLocation"
    FOREIGN KEY ("object_id")
    REFERENCES "BindingFeature" ("unipaxId")
    ON DELETE CASCADE);

CREATE INDEX "BindingFeature_featureLocation"
  ON "BindingFeature_featureLocation" ("object_id");

CREATE INDEX "BindingFeature_featureLocation"
  ON "BindingFeature_featureLocation" ("index");

CREATE TABLE "BindingFeature_id_bindsTo" (
  "object_id" NUMBER(20) NOT NULL,
  "index" NUMBER(20) NOT NULL,
  "value" NUMBER(20) NOT NULL,
  CONSTRAINT "BindingFeature_id_bindsTo_obje"
    FOREIGN KEY ("object_id")
    REFERENCES "BindingFeature" ("unipaxId")
    ON DELETE CASCADE);

CREATE INDEX "BindingFeature_id_bindsTo_obje"
  ON "BindingFeature_id_bindsTo" ("object_id");

CREATE INDEX "BindingFeature_id_bindsTo_inde"
  ON "BindingFeature_id_bindsTo" ("index");

ALTER TABLE "BindingFeature" ADD
  CONSTRAINT "BindingFeature_unipaxSource_fk"
    FOREIGN KEY ("unipaxSource")
    REFERENCES "ImportSource" ("unipaxId")
    DEFERRABLE INITIALLY DEFERRED;

ALTER TABLE "BindingFeature_evidence" ADD
  CONSTRAINT "BindingFeature_evidence_value_"
    FOREIGN KEY ("value")
    REFERENCES "Evidence" ("unipaxId")
    DEFERRABLE INITIALLY DEFERRED;

ALTER TABLE "BindingFeature_featureLocation" ADD
  CONSTRAINT "BindingFeature_featureLocation"
    FOREIGN KEY ("value")
    REFERENCES "SequenceRegionVocabulary" ("unipaxId")
    DEFERRABLE INITIALLY DEFERRED;

EXIT;
