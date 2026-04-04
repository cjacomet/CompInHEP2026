Example B4 is used to simulate a simple sampling calorimeter.
(https://geant4-userdoc.web.cern.ch/Doxygen/examples_doc/html/ExampleB4.html)

This is a detector which consists of alternating layers of 'absorber' and 'gap'.
The absorber is a material in which particle showers are produced by the incoming particles.
The energy from these particle showers can then be detected in the gap material.

The detector in example B4 is a simple rectangular box. The number of layers and their thickness, 
as well as the material they are made of can be adapted by the user.
The default materials are lead as absorber and argon gas as gap.
The default constructor geometry is 10cmx10cm with 10 layers of 10mm absorber followed by 5mm gap.
(All defined in B4a/src/DetectorConstruction.cc)

Simulate by running:
./run_particle.job <particle> "<energy>"

So: 
./run_particle.job e- "10 GeV"
./run_particle.job proton "10 GeV"
./run_particle.job alpha "10 GeV"

To simulate with different absorber material run:
./run_particle.job <particle> "<energy>" <abs_material>

So for water: 
./run_particle.job e- "10 GeV" G4_WATER
./run_particle.job proton "10 GeV" G4_WATER
./run_particle.job alpha "10 GeV" G4_WATER