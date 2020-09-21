
// local headers to include
#include "UserDefinedDetectorConstruction.hh"

// classes to include from the Geant4 framework
// #include "globals.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"

// a constructor that does nothing except call its parent's constructor
UserDefinedDetectorConstruction::UserDefinedDetectorConstruction()
: G4VUserDetectorConstruction()
{}

// empty destructor
UserDefinedDetectorConstruction::~UserDefinedDetectorConstruction()
{}

// this method is called when the run is initialized and builds the simulation world
G4VPhysicalVolume* UserDefinedDetectorConstruction::Construct()
{
  // Get nist material manager for easy material management
  G4NistManager* nist = G4NistManager::Instance();

  // shape of the world
  // passing a reference name and HALF values of the edges
  // the world will be 1m*1m*1m
  G4Box* world_shape = new G4Box("WorldBox", 0.5*m, 0.5*m, 0.5*m);

  // attach attributes to the world shape
  G4LogicalVolume* world_logic = new G4LogicalVolume(
    world_shape, //its shape
    nist->FindOrBuildMaterial("G4_AIR"), //its material
    "WorldWithAttrs" //its name
  );
  // world object placed in the simulation
  G4VPhysicalVolume* world = new G4PVPlacement(
    0,                 // no rotation
    G4ThreeVector(),   // at (0,0,0)
    world_logic,       // its logical volume
    "WorldPlacement",  // some reference name
     0,                //its mother volume - aka none
     false,            //no boolean operation - not important here
     0,                //copy number - not important here
     true              //overlaps checking - not important here
   );

  return world;
}
