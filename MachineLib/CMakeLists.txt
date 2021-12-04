project(MachineLib)

set(SOURCE_FILES
        pch.h
        Machine.h Machine.cpp
        MachineFactory.cpp MachineFactory.h
        MachineStandin.cpp MachineStandin.h
        MachineDialog.cpp MachineDialog.h include/machine-api.h Motor.cpp Motor.h MachineDerived.cpp MachineDerived.h
        ActualMachine.cpp ActualMachine.h MachineOneFactory.cpp MachineOneFactory.h Component.cpp Component.h
        Polygon.cpp Polygon.h MachineTwoFactory.cpp MachineTwoFactory.h
        Gear.cpp Gear.h SourceRotate.cpp SourceRotate.h SinkRotation.cpp SinkRotation.h Shape.cpp Shape.h Arm.cpp Arm.h Rod.cpp Rod.h SinkPosition.cpp SinkPosition.h SourcePosition.cpp SourcePosition.h Lever.cpp Lever.h INegotiator.cpp INegotiator.h)

find_package(wxWidgets COMPONENTS core base xrc html xml REQUIRED)
include(${wxWidgets_USE_FILE})

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
target_precompile_headers(${PROJECT_NAME} PRIVATE pch.h)