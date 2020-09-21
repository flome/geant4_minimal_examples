
// classes to include from the Geant4 framework
#include "G4RunManager.hh"
#include "G4UIExecutive.hh"
#include "Shielding.hh"

// user defined classes to include
#include "UserDefinedDetectorConstruction.hh"
#include "UserDefinedActionInitialization.hh"

int main(int argc, char** argv){

  // create instance that sets up the simulation and guides the run
  G4RunManager* runManager = new G4RunManager();

  // which physics processes should be used for the simulation
  runManager->SetUserInitialization(new Shielding);

  // world and detector setup for the simulation
  runManager->SetUserInitialization(new UserDefinedDetectorConstruction);

  // actions during the simulation including the generation of particles
  runManager->SetUserInitialization(new UserDefinedActionInitialization);

  // run a macro file
  G4UIExecutive *commandLineInterface = new G4UIExecutive(argc, argv, "tcsh");
  commandLineInterface->SessionStart();

  delete commandLineInterface;
  delete runManager;
  return 0;
}
