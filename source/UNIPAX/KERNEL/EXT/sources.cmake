SET(SOURCES_LIST
AlgebraicRule.cpp
AssignmentRule.cpp
Constraint.cpp
Delay.cpp
Event.cpp
EventAssignment.cpp
Experiment.cpp
FunctionDefinition.cpp
IdMapping.cpp
ImportSource.cpp
InitialAssignment.cpp
KineticLaw.cpp
LocalParameter.cpp
Math.cpp
Model.cpp
Parameter.cpp
Priority.cpp
RateRule.cpp
ResultObject.cpp
Rule.cpp
Sample.cpp
SBase.cpp
Sample.cpp
SampleData.cpp
Series.cpp
Trigger.cpp
UIBase.cpp
UPBase.cpp
Unit.cpp
UnitDefinition.cpp
)
ADD_UNIPAX_SOURCES("KERNEL/EXT" "${SOURCES_LIST}")
