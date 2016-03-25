/* This file was generated by ODB, object-relational mapping (ORM)
 * compiler for C++.
 */

SET FEEDBACK OFF;
WHENEVER SQLERROR EXIT FAILURE;
WHENEVER OSERROR EXIT FAILURE;

BEGIN
  BEGIN
    EXECUTE IMMEDIATE 'DROP TABLE "Event_eventAssignment" CASCADE CONSTRAINTS';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -942 THEN RAISE; END IF;
  END;  BEGIN
    EXECUTE IMMEDIATE 'DROP SEQUENCE "Event_eventAssignment_seq"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -2289 THEN RAISE; END IF;
  END;
  BEGIN
    EXECUTE IMMEDIATE 'DROP TRIGGER "Event_eventAssignment_trg"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -4080 THEN RAISE; END IF;
  END;
END;
/

BEGIN
  BEGIN
    EXECUTE IMMEDIATE 'DROP TABLE "Event" CASCADE CONSTRAINTS';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -942 THEN RAISE; END IF;
  END;  BEGIN
    EXECUTE IMMEDIATE 'DROP SEQUENCE "Event_seq"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -2289 THEN RAISE; END IF;
  END;
  BEGIN
    EXECUTE IMMEDIATE 'DROP TRIGGER "Event_trg"';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -4080 THEN RAISE; END IF;
  END;
END;
/


CREATE TABLE "Event" (
  "unipaxId" NUMBER(20) NOT NULL PRIMARY KEY,
  "unipaxSource" NUMBER(20),
  "metaId" VARCHAR2(512),
  "sboTerm" VARCHAR2(512),
  "notes" VARCHAR2(512),
  "annotation" VARCHAR2(512),
  "useValuesFromTriggerTime" NUMBER(1) NOT NULL,
  "id" VARCHAR2(512),
  "name" VARCHAR2(512),
  "priority" NUMBER(20),
  "delay" NUMBER(20),
  "trigger" NUMBER(20));

CREATE TABLE "Event_eventAssignment" (
  "object_id" NUMBER(20) NOT NULL,
  "index" NUMBER(20) NOT NULL,
  "value" NUMBER(20),
  CONSTRAINT "Event_eventAssignment_object_i"
    FOREIGN KEY ("object_id")
    REFERENCES "Event" ("unipaxId")
    ON DELETE CASCADE);

CREATE INDEX "Event_eventAssignment_object_i"
  ON "Event_eventAssignment" ("object_id");

CREATE INDEX "Event_eventAssignment_index_i"
  ON "Event_eventAssignment" ("index");

ALTER TABLE "Event" ADD
  CONSTRAINT "Event_unipaxSource_fk"
    FOREIGN KEY ("unipaxSource")
    REFERENCES "ImportSource" ("unipaxId")
    DEFERRABLE INITIALLY DEFERRED;

ALTER TABLE "Event" ADD
  CONSTRAINT "Event_priority_fk"
    FOREIGN KEY ("priority")
    REFERENCES "Priority" ("unipaxId")
    DEFERRABLE INITIALLY DEFERRED;

ALTER TABLE "Event" ADD
  CONSTRAINT "Event_delay_fk"
    FOREIGN KEY ("delay")
    REFERENCES "Delay" ("unipaxId")
    DEFERRABLE INITIALLY DEFERRED;

ALTER TABLE "Event" ADD
  CONSTRAINT "Event_trigger_fk"
    FOREIGN KEY ("trigger")
    REFERENCES "Trigger" ("unipaxId")
    DEFERRABLE INITIALLY DEFERRED;

ALTER TABLE "Event_eventAssignment" ADD
  CONSTRAINT "Event_eventAssignment_value_fk"
    FOREIGN KEY ("value")
    REFERENCES "EventAssignment" ("unipaxId")
    DEFERRABLE INITIALLY DEFERRED;

EXIT;