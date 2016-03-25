SET(SOURCES_LIST
AlgebraicRule-odb.cxx
AssignmentRule-odb.cxx
Constraint-odb.cxx
Delay-odb.cxx
Event-odb.cxx
EventAssignment-odb.cxx
Experiment-odb.cxx
FunctionDefinition-odb.cxx
ImportSource-odb.cxx
InitialAssignment-odb.cxx
KineticLaw-odb.cxx
LocalParameter-odb.cxx
Mapping-odb.cxx
Math-odb.cxx
Model-odb.cxx
Parameter-odb.cxx
Priority-odb.cxx
RateRule-odb.cxx
Rule-odb.cxx
SBase-odb.cxx
Sample-odb.cxx
Trigger-odb.cxx
UPBase-odb.cxx
UIBase-odb.cxx
Unit-odb.cxx
UnitDefinition-odb.cxx
)
ADD_UNIPAX_SOURCES("PERSISTENCE/ORACLE/EXT" "${SOURCES_LIST}")
