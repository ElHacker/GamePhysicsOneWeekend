g++ -c -DPHYSICSLIBRARY_EXPORTS PhysicsLibrary.cpp ../Physics/Body.cpp ../Physics/Shapes/ShapeSphere.cpp
g++ -shared -o PhysicsLibrary.dll PhysicsLibrary.o Body.o ShapeSphere.o -Wl,--out-implib,libPhysicsLibrary.a
