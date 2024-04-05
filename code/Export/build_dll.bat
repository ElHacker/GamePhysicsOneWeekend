g++ -c -DPHYSICSLIBRARY_EXPORTS PhysicsLibrary.cpp ../Physics/Body.cpp ../Physics/Shapes/ShapeSphere.cpp ../Scene.cpp ../Physics/Constraints/ConstraintPenetration.cpp ../Physics/Broadphase.cpp ../Physics/Intersections.cpp ../Physics/Contact.cpp ../Math/Bounds.cpp ./DebugCPP.cpp
g++ -shared -o PhysicsLibrary.dll PhysicsLibrary.o Body.o ShapeSphere.o Scene.o ConstraintPenetration.o Broadphase.o Intersections.o Contact.o Bounds.o DebugCPP.o -Wl,--out-implib,libPhysicsLibrary.a