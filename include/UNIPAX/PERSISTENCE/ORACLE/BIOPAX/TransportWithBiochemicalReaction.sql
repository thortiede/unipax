/* This file was generated by ODB, object-relational mapping (ORM)
 * compiler for C++.
 */

SET FEEDBACK OFF;
WHENEVER SQLERROR EXIT FAILURE;
WHENEVER OSERROR EXIT FAILURE;

BEGIN
  BEGIN
    EXECUTE IMMEDIATE 'DROP TABLE "TransportWithBiochemicalReaction_kEQ" CASCADE CONSTRAINTS';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -942 THEN RAISE; END IF;
  END;  BEGIN
    EXECUTE IMMEDIATE 'DROP SEQUENCE "TransportWithBiochemicalReaction_kEQ_seq"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -2289 THEN RAISE; END IF;
  END;
  BEGIN
    EXECUTE IMMEDIATE 'DROP TRIGGER "TransportWithBiochemicalReaction_kEQ_trg"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -4080 THEN RAISE; END IF;
  END;
END;
/

BEGIN
  BEGIN
    EXECUTE IMMEDIATE 'DROP TABLE "TransportWithBiochemicalReaction_deltaG" CASCADE CONSTRAINTS';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -942 THEN RAISE; END IF;
  END;  BEGIN
    EXECUTE IMMEDIATE 'DROP SEQUENCE "TransportWithBiochemicalReaction_deltaG_se"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -2289 THEN RAISE; END IF;
  END;
  BEGIN
    EXECUTE IMMEDIATE 'DROP TRIGGER "TransportWithBiochemicalReaction_deltaG_tr"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -4080 THEN RAISE; END IF;
  END;
END;
/

BEGIN
  BEGIN
    EXECUTE IMMEDIATE 'DROP TABLE "TransportWithBiochemicalReaction_id_rightE" CASCADE CONSTRAINTS';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -942 THEN RAISE; END IF;
  END;  BEGIN
    EXECUTE IMMEDIATE 'DROP SEQUENCE "TransportWithBiochemicalReaction_id_rightE"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -2289 THEN RAISE; END IF;
  END;
  BEGIN
    EXECUTE IMMEDIATE 'DROP TRIGGER "TransportWithBiochemicalReaction_id_rightE"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -4080 THEN RAISE; END IF;
  END;
END;
/

BEGIN
  BEGIN
    EXECUTE IMMEDIATE 'DROP TABLE "TransportWithBiochemicalReaction_id_leftEn" CASCADE CONSTRAINTS';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -942 THEN RAISE; END IF;
  END;  BEGIN
    EXECUTE IMMEDIATE 'DROP SEQUENCE "TransportWithBiochemicalReaction_id_leftEn"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -2289 THEN RAISE; END IF;
  END;
  BEGIN
    EXECUTE IMMEDIATE 'DROP TRIGGER "TransportWithBiochemicalReaction_id_leftEn"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -4080 THEN RAISE; END IF;
  END;
END;
/

BEGIN
  BEGIN
    EXECUTE IMMEDIATE 'DROP TABLE "TransportWithBiochemicalReaction_participa" CASCADE CONSTRAINTS';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -942 THEN RAISE; END IF;
  END;  BEGIN
    EXECUTE IMMEDIATE 'DROP SEQUENCE "TransportWithBiochemicalReaction_participa"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -2289 THEN RAISE; END IF;
  END;
  BEGIN
    EXECUTE IMMEDIATE 'DROP TRIGGER "TransportWithBiochemicalReaction_participa"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -4080 THEN RAISE; END IF;
  END;
END;
/

BEGIN
  BEGIN
    EXECUTE IMMEDIATE 'DROP TABLE "TransportWithBiochemicalReaction_interacti" CASCADE CONSTRAINTS';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -942 THEN RAISE; END IF;
  END;  BEGIN
    EXECUTE IMMEDIATE 'DROP SEQUENCE "TransportWithBiochemicalReaction_interacti"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -2289 THEN RAISE; END IF;
  END;
  BEGIN
    EXECUTE IMMEDIATE 'DROP TRIGGER "TransportWithBiochemicalReaction_interacti"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -4080 THEN RAISE; END IF;
  END;
END;
/

BEGIN
  BEGIN
    EXECUTE IMMEDIATE 'DROP TABLE "TransportWithBiochemicalReaction_id_partic" CASCADE CONSTRAINTS';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -942 THEN RAISE; END IF;
  END;  BEGIN
    EXECUTE IMMEDIATE 'DROP SEQUENCE "TransportWithBiochemicalReaction_id_partic"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -2289 THEN RAISE; END IF;
  END;
  BEGIN
    EXECUTE IMMEDIATE 'DROP TRIGGER "TransportWithBiochemicalReaction_id_partic"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -4080 THEN RAISE; END IF;
  END;
END;
/

BEGIN
  BEGIN
    EXECUTE IMMEDIATE 'DROP TABLE "TransportWithBiochemicalReaction_id_xref" CASCADE CONSTRAINTS';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -942 THEN RAISE; END IF;
  END;  BEGIN
    EXECUTE IMMEDIATE 'DROP SEQUENCE "TransportWithBiochemicalReaction_id_xref_s"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -2289 THEN RAISE; END IF;
  END;
  BEGIN
    EXECUTE IMMEDIATE 'DROP TRIGGER "TransportWithBiochemicalReaction_id_xref_t"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -4080 THEN RAISE; END IF;
  END;
END;
/

BEGIN
  BEGIN
    EXECUTE IMMEDIATE 'DROP TABLE "TransportWithBiochemicalReaction_name" CASCADE CONSTRAINTS';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -942 THEN RAISE; END IF;
  END;  BEGIN
    EXECUTE IMMEDIATE 'DROP SEQUENCE "TransportWithBiochemicalReaction_name_seq"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -2289 THEN RAISE; END IF;
  END;
  BEGIN
    EXECUTE IMMEDIATE 'DROP TRIGGER "TransportWithBiochemicalReaction_name_trg"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -4080 THEN RAISE; END IF;
  END;
END;
/

BEGIN
  BEGIN
    EXECUTE IMMEDIATE 'DROP TABLE "TransportWithBiochemicalReaction_comments" CASCADE CONSTRAINTS';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -942 THEN RAISE; END IF;
  END;  BEGIN
    EXECUTE IMMEDIATE 'DROP SEQUENCE "TransportWithBiochemicalReaction_comments_"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -2289 THEN RAISE; END IF;
  END;
  BEGIN
    EXECUTE IMMEDIATE 'DROP TRIGGER "TransportWithBiochemicalReaction_comments_"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -4080 THEN RAISE; END IF;
  END;
END;
/

BEGIN
  BEGIN
    EXECUTE IMMEDIATE 'DROP TABLE "TransportWithBiochemicalReaction" CASCADE CONSTRAINTS';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -942 THEN RAISE; END IF;
  END;  BEGIN
    EXECUTE IMMEDIATE 'DROP SEQUENCE "TransportWithBiochemicalReaction_seq"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -2289 THEN RAISE; END IF;
  END;
  BEGIN
    EXECUTE IMMEDIATE 'DROP TRIGGER "TransportWithBiochemicalReaction_trg"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -4080 THEN RAISE; END IF;
  END;
END;
/


CREATE TABLE "TransportWithBiochemicalReaction" (
  "unipaxId" NUMBER(20) NOT NULL PRIMARY KEY,
  "unipaxSource" NUMBER(20),
  "availability" VARCHAR2(512),
  "standardName" VARCHAR2(512),
  "displayName" VARCHAR2(512),
  "evidence" NUMBER(20),
  "dataSource" NUMBER(20),
  "conversionDirection" VARCHAR2(512),
  "spontaneous" NUMBER(1) NOT NULL,
  "kineticLaw" NUMBER(20),
  "deltaH" BINARY_DOUBLE NOT NULL,
  "deltaS" BINARY_DOUBLE NOT NULL,
  "eCNumber" VARCHAR2(512));

CREATE TABLE "TransportWithBiochemicalReaction_comments" (
  "object_id" NUMBER(20) NOT NULL,
  "index" NUMBER(20) NOT NULL,
  "value" VARCHAR2(512),
  CONSTRAINT "TransportWithBiochemicalReaction_comments_"
    FOREIGN KEY ("object_id")
    REFERENCES "TransportWithBiochemicalReaction" ("unipaxId")
    ON DELETE CASCADE);

CREATE INDEX "TransportWithBiochemicalReaction_comments_"
  ON "TransportWithBiochemicalReaction_comments" ("object_id");

CREATE INDEX "TransportWithBiochemicalReaction_comments_"
  ON "TransportWithBiochemicalReaction_comments" ("index");

CREATE TABLE "TransportWithBiochemicalReaction_name" (
  "object_id" NUMBER(20) NOT NULL,
  "index" NUMBER(20) NOT NULL,
  "value" VARCHAR2(512),
  CONSTRAINT "TransportWithBiochemicalReaction_name_obje"
    FOREIGN KEY ("object_id")
    REFERENCES "TransportWithBiochemicalReaction" ("unipaxId")
    ON DELETE CASCADE);

CREATE INDEX "TransportWithBiochemicalReaction_name_obje"
  ON "TransportWithBiochemicalReaction_name" ("object_id");

CREATE INDEX "TransportWithBiochemicalReaction_name_inde"
  ON "TransportWithBiochemicalReaction_name" ("index");

CREATE TABLE "TransportWithBiochemicalReaction_id_xref" (
  "object_id" NUMBER(20) NOT NULL,
  "index" NUMBER(20) NOT NULL,
  "value" NUMBER(20) NOT NULL,
  CONSTRAINT "TransportWithBiochemicalReaction_id_xref_o"
    FOREIGN KEY ("object_id")
    REFERENCES "TransportWithBiochemicalReaction" ("unipaxId")
    ON DELETE CASCADE);

CREATE INDEX "TransportWithBiochemicalReaction_id_xref_o"
  ON "TransportWithBiochemicalReaction_id_xref" ("object_id");

CREATE INDEX "TransportWithBiochemicalReaction_id_xref_i"
  ON "TransportWithBiochemicalReaction_id_xref" ("index");

CREATE TABLE "TransportWithBiochemicalReaction_id_partic" (
  "object_id" NUMBER(20) NOT NULL,
  "index" NUMBER(20) NOT NULL,
  "value" NUMBER(20) NOT NULL,
  CONSTRAINT "TransportWithBiochemicalReaction_id_partic"
    FOREIGN KEY ("object_id")
    REFERENCES "TransportWithBiochemicalReaction" ("unipaxId")
    ON DELETE CASCADE);

CREATE INDEX "TransportWithBiochemicalReaction_id_partic"
  ON "TransportWithBiochemicalReaction_id_partic" ("object_id");

CREATE INDEX "TransportWithBiochemicalReaction_id_partic"
  ON "TransportWithBiochemicalReaction_id_partic" ("index");

CREATE TABLE "TransportWithBiochemicalReaction_interacti" (
  "object_id" NUMBER(20) NOT NULL,
  "index" NUMBER(20) NOT NULL,
  "value" NUMBER(20),
  CONSTRAINT "TransportWithBiochemicalReaction_interacti"
    FOREIGN KEY ("object_id")
    REFERENCES "TransportWithBiochemicalReaction" ("unipaxId")
    ON DELETE CASCADE);

CREATE INDEX "TransportWithBiochemicalReaction_interacti"
  ON "TransportWithBiochemicalReaction_interacti" ("object_id");

CREATE INDEX "TransportWithBiochemicalReaction_interacti"
  ON "TransportWithBiochemicalReaction_interacti" ("index");

CREATE TABLE "TransportWithBiochemicalReaction_participa" (
  "object_id" NUMBER(20) NOT NULL,
  "index" NUMBER(20) NOT NULL,
  "value" NUMBER(20),
  CONSTRAINT "TransportWithBiochemicalReaction_participa"
    FOREIGN KEY ("object_id")
    REFERENCES "TransportWithBiochemicalReaction" ("unipaxId")
    ON DELETE CASCADE);

CREATE INDEX "TransportWithBiochemicalReaction_participa"
  ON "TransportWithBiochemicalReaction_participa" ("object_id");

CREATE INDEX "TransportWithBiochemicalReaction_participa"
  ON "TransportWithBiochemicalReaction_participa" ("index");

CREATE TABLE "TransportWithBiochemicalReaction_id_leftEn" (
  "object_id" NUMBER(20) NOT NULL,
  "index" NUMBER(20) NOT NULL,
  "value" NUMBER(20) NOT NULL,
  CONSTRAINT "TransportWithBiochemicalReaction_id_leftEn"
    FOREIGN KEY ("object_id")
    REFERENCES "TransportWithBiochemicalReaction" ("unipaxId")
    ON DELETE CASCADE);

CREATE INDEX "TransportWithBiochemicalReaction_id_leftEn"
  ON "TransportWithBiochemicalReaction_id_leftEn" ("object_id");

CREATE INDEX "TransportWithBiochemicalReaction_id_leftEn"
  ON "TransportWithBiochemicalReaction_id_leftEn" ("index");

CREATE TABLE "TransportWithBiochemicalReaction_id_rightE" (
  "object_id" NUMBER(20) NOT NULL,
  "index" NUMBER(20) NOT NULL,
  "value" NUMBER(20) NOT NULL,
  CONSTRAINT "TransportWithBiochemicalReaction_id_rightE"
    FOREIGN KEY ("object_id")
    REFERENCES "TransportWithBiochemicalReaction" ("unipaxId")
    ON DELETE CASCADE);

CREATE INDEX "TransportWithBiochemicalReaction_id_rightE"
  ON "TransportWithBiochemicalReaction_id_rightE" ("object_id");

CREATE INDEX "TransportWithBiochemicalReaction_id_rightE"
  ON "TransportWithBiochemicalReaction_id_rightE" ("index");

CREATE TABLE "TransportWithBiochemicalReaction_deltaG" (
  "object_id" NUMBER(20) NOT NULL,
  "index" NUMBER(20) NOT NULL,
  "value" NUMBER(20),
  CONSTRAINT "TransportWithBiochemicalReaction_deltaG_ob"
    FOREIGN KEY ("object_id")
    REFERENCES "TransportWithBiochemicalReaction" ("unipaxId")
    ON DELETE CASCADE);

CREATE INDEX "TransportWithBiochemicalReaction_deltaG_ob"
  ON "TransportWithBiochemicalReaction_deltaG" ("object_id");

CREATE INDEX "TransportWithBiochemicalReaction_deltaG_in"
  ON "TransportWithBiochemicalReaction_deltaG" ("index");

CREATE TABLE "TransportWithBiochemicalReaction_kEQ" (
  "object_id" NUMBER(20) NOT NULL,
  "index" NUMBER(20) NOT NULL,
  "value" NUMBER(20),
  CONSTRAINT "TransportWithBiochemicalReaction_kEQ_objec"
    FOREIGN KEY ("object_id")
    REFERENCES "TransportWithBiochemicalReaction" ("unipaxId")
    ON DELETE CASCADE);

CREATE INDEX "TransportWithBiochemicalReaction_kEQ_objec"
  ON "TransportWithBiochemicalReaction_kEQ" ("object_id");

CREATE INDEX "TransportWithBiochemicalReaction_kEQ_index"
  ON "TransportWithBiochemicalReaction_kEQ" ("index");

ALTER TABLE "TransportWithBiochemicalReaction" ADD
  CONSTRAINT "TransportWithBiochemicalReaction_unipaxSou"
    FOREIGN KEY ("unipaxSource")
    REFERENCES "ImportSource" ("unipaxId")
    DEFERRABLE INITIALLY DEFERRED;

ALTER TABLE "TransportWithBiochemicalReaction" ADD
  CONSTRAINT "TransportWithBiochemicalReaction_evidence_"
    FOREIGN KEY ("evidence")
    REFERENCES "Evidence" ("unipaxId")
    DEFERRABLE INITIALLY DEFERRED;

ALTER TABLE "TransportWithBiochemicalReaction" ADD
  CONSTRAINT "TransportWithBiochemicalReaction_dataSourc"
    FOREIGN KEY ("dataSource")
    REFERENCES "Provenance" ("unipaxId")
    DEFERRABLE INITIALLY DEFERRED;

ALTER TABLE "TransportWithBiochemicalReaction" ADD
  CONSTRAINT "TransportWithBiochemicalReaction_kineticLa"
    FOREIGN KEY ("kineticLaw")
    REFERENCES "KineticLaw" ("unipaxId")
    DEFERRABLE INITIALLY DEFERRED;

ALTER TABLE "TransportWithBiochemicalReaction_interacti" ADD
  CONSTRAINT "TransportWithBiochemicalReaction_interacti"
    FOREIGN KEY ("value")
    REFERENCES "InteractionVocabulary" ("unipaxId")
    DEFERRABLE INITIALLY DEFERRED;

ALTER TABLE "TransportWithBiochemicalReaction_participa" ADD
  CONSTRAINT "TransportWithBiochemicalReaction_participa"
    FOREIGN KEY ("value")
    REFERENCES "Stoichiometry" ("unipaxId")
    DEFERRABLE INITIALLY DEFERRED;

ALTER TABLE "TransportWithBiochemicalReaction_deltaG" ADD
  CONSTRAINT "TransportWithBiochemicalReaction_deltaG_va"
    FOREIGN KEY ("value")
    REFERENCES "DeltaG" ("unipaxId")
    DEFERRABLE INITIALLY DEFERRED;

ALTER TABLE "TransportWithBiochemicalReaction_kEQ" ADD
  CONSTRAINT "TransportWithBiochemicalReaction_kEQ_value"
    FOREIGN KEY ("value")
    REFERENCES "KPrime" ("unipaxId")
    DEFERRABLE INITIALLY DEFERRED;

EXIT;
