/* This file was generated by ODB, object-relational mapping (ORM)
 * compiler for C++.
 */

SET FEEDBACK OFF;
WHENEVER SQLERROR EXIT FAILURE;
WHENEVER OSERROR EXIT FAILURE;

BEGIN
  BEGIN
    EXECUTE IMMEDIATE 'DROP TABLE "EntityFeature_featureLocationT" CASCADE CONSTRAINTS';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -942 THEN RAISE; END IF;
  END;  BEGIN
    EXECUTE IMMEDIATE 'DROP SEQUENCE "EntityFeature_featureLocationT"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -2289 THEN RAISE; END IF;
  END;
  BEGIN
    EXECUTE IMMEDIATE 'DROP TRIGGER "EntityFeature_featureLocationT"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -4080 THEN RAISE; END IF;
  END;
END;
/

BEGIN
  BEGIN
    EXECUTE IMMEDIATE 'DROP TABLE "EntityFeature_id_featureLocati" CASCADE CONSTRAINTS';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -942 THEN RAISE; END IF;
  END;  BEGIN
    EXECUTE IMMEDIATE 'DROP SEQUENCE "EntityFeature_id_featureLocati"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -2289 THEN RAISE; END IF;
  END;
  BEGIN
    EXECUTE IMMEDIATE 'DROP TRIGGER "EntityFeature_id_featureLocati"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -4080 THEN RAISE; END IF;
  END;
END;
/

BEGIN
  BEGIN
    EXECUTE IMMEDIATE 'DROP TABLE "EntityFeature_id_memberFeature" CASCADE CONSTRAINTS';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -942 THEN RAISE; END IF;
  END;  BEGIN
    EXECUTE IMMEDIATE 'DROP SEQUENCE "EntityFeature_id_memberFeature"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -2289 THEN RAISE; END IF;
  END;
  BEGIN
    EXECUTE IMMEDIATE 'DROP TRIGGER "EntityFeature_id_memberFeature"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -4080 THEN RAISE; END IF;
  END;
END;
/

BEGIN
  BEGIN
    EXECUTE IMMEDIATE 'DROP TABLE "EntityFeature_evidence" CASCADE CONSTRAINTS';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -942 THEN RAISE; END IF;
  END;  BEGIN
    EXECUTE IMMEDIATE 'DROP SEQUENCE "EntityFeature_evidence_seq"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -2289 THEN RAISE; END IF;
  END;
  BEGIN
    EXECUTE IMMEDIATE 'DROP TRIGGER "EntityFeature_evidence_trg"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -4080 THEN RAISE; END IF;
  END;
END;
/

BEGIN
  BEGIN
    EXECUTE IMMEDIATE 'DROP TABLE "EntityFeature_comment" CASCADE CONSTRAINTS';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -942 THEN RAISE; END IF;
  END;  BEGIN
    EXECUTE IMMEDIATE 'DROP SEQUENCE "EntityFeature_comment_seq"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -2289 THEN RAISE; END IF;
  END;
  BEGIN
    EXECUTE IMMEDIATE 'DROP TRIGGER "EntityFeature_comment_trg"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -4080 THEN RAISE; END IF;
  END;
END;
/

BEGIN
  BEGIN
    EXECUTE IMMEDIATE 'DROP TABLE "EntityFeature" CASCADE CONSTRAINTS';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -942 THEN RAISE; END IF;
  END;  BEGIN
    EXECUTE IMMEDIATE 'DROP SEQUENCE "EntityFeature_seq"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -2289 THEN RAISE; END IF;
  END;
  BEGIN
    EXECUTE IMMEDIATE 'DROP TRIGGER "EntityFeature_trg"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -4080 THEN RAISE; END IF;
  END;
END;
/


CREATE TABLE "EntityFeature" (
  "unipaxId" NUMBER(20) NOT NULL PRIMARY KEY,
  "unipaxSource" NUMBER(20));

CREATE TABLE "EntityFeature_comment" (
  "object_id" NUMBER(20) NOT NULL,
  "index" NUMBER(20) NOT NULL,
  "value" VARCHAR2(512),
  CONSTRAINT "EntityFeature_comment_object_i"
    FOREIGN KEY ("object_id")
    REFERENCES "EntityFeature" ("unipaxId")
    ON DELETE CASCADE);

CREATE INDEX "EntityFeature_comment_object_i"
  ON "EntityFeature_comment" ("object_id");

CREATE INDEX "EntityFeature_comment_index_i"
  ON "EntityFeature_comment" ("index");

CREATE TABLE "EntityFeature_evidence" (
  "object_id" NUMBER(20) NOT NULL,
  "index" NUMBER(20) NOT NULL,
  "value" NUMBER(20),
  CONSTRAINT "EntityFeature_evidence_object_"
    FOREIGN KEY ("object_id")
    REFERENCES "EntityFeature" ("unipaxId")
    ON DELETE CASCADE);

CREATE INDEX "EntityFeature_evidence_object_"
  ON "EntityFeature_evidence" ("object_id");

CREATE INDEX "EntityFeature_evidence_index_i"
  ON "EntityFeature_evidence" ("index");

CREATE TABLE "EntityFeature_id_memberFeature" (
  "object_id" NUMBER(20) NOT NULL,
  "index" NUMBER(20) NOT NULL,
  "value" NUMBER(20) NOT NULL,
  CONSTRAINT "EntityFeature_id_memberFeature"
    FOREIGN KEY ("object_id")
    REFERENCES "EntityFeature" ("unipaxId")
    ON DELETE CASCADE);

CREATE INDEX "EntityFeature_id_memberFeature"
  ON "EntityFeature_id_memberFeature" ("object_id");

CREATE INDEX "EntityFeature_id_memberFeature"
  ON "EntityFeature_id_memberFeature" ("index");

CREATE TABLE "EntityFeature_id_featureLocati" (
  "object_id" NUMBER(20) NOT NULL,
  "index" NUMBER(20) NOT NULL,
  "value" NUMBER(20) NOT NULL,
  CONSTRAINT "EntityFeature_id_featureLocati"
    FOREIGN KEY ("object_id")
    REFERENCES "EntityFeature" ("unipaxId")
    ON DELETE CASCADE);

CREATE INDEX "EntityFeature_id_featureLocati"
  ON "EntityFeature_id_featureLocati" ("object_id");

CREATE INDEX "EntityFeature_id_featureLocati"
  ON "EntityFeature_id_featureLocati" ("index");

CREATE TABLE "EntityFeature_featureLocationT" (
  "object_id" NUMBER(20) NOT NULL,
  "index" NUMBER(20) NOT NULL,
  "value" NUMBER(20),
  CONSTRAINT "EntityFeature_featureLocationT"
    FOREIGN KEY ("object_id")
    REFERENCES "EntityFeature" ("unipaxId")
    ON DELETE CASCADE);

CREATE INDEX "EntityFeature_featureLocationT"
  ON "EntityFeature_featureLocationT" ("object_id");

CREATE INDEX "EntityFeature_featureLocationT"
  ON "EntityFeature_featureLocationT" ("index");

ALTER TABLE "EntityFeature" ADD
  CONSTRAINT "EntityFeature_unipaxSource_fk"
    FOREIGN KEY ("unipaxSource")
    REFERENCES "ImportSource" ("unipaxId")
    DEFERRABLE INITIALLY DEFERRED;

ALTER TABLE "EntityFeature_evidence" ADD
  CONSTRAINT "EntityFeature_evidence_value_f"
    FOREIGN KEY ("value")
    REFERENCES "Evidence" ("unipaxId")
    DEFERRABLE INITIALLY DEFERRED;

ALTER TABLE "EntityFeature_featureLocationT" ADD
  CONSTRAINT "EntityFeature_featureLocationT"
    FOREIGN KEY ("value")
    REFERENCES "SequenceRegionVocabulary" ("unipaxId")
    DEFERRABLE INITIALLY DEFERRED;

EXIT;