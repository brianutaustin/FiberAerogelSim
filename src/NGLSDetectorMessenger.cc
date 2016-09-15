#include "NGLSDetectorMessenger.hh"
#include "NGLSDetectorConstruction.hh"

#include "G4UIdirectory.hh"
#include "G4UIcmdWithAString.hh"
#include "G4UIcmdWithADoubleAndUnit.hh"

NGLSDetectorMessenger::NGLSDetectorMessenger(NGLSDetectorConstruction * Det)
  : G4UImessenger(),
  fDetectorConstruction(Det) {
  fNGLSDirectory = new G4UIdirectory("/NGLS/");
  fNGLSDirectory->SetGuidance("UI commands specific to this example.");

  fDetDirectory = new G4UIdirectory("/NGLS/det/");
  fDetDirectory->SetGuidance("Detector construction control");

  fTargMatCmd = new G4UIcmdWithAString("/NGLS/det/setTargetMaterial", this);
  fTargMatCmd->SetGuidance("Select Material of the Target.");
  fTargMatCmd->SetParameterName("choice", false);
  fTargMatCmd->AvailableForStates(G4State_PreInit, G4State_Idle);

  fChamMatCmd = new G4UIcmdWithAString("/NGLS/det/setChamberMaterial", this);
  fChamMatCmd->SetGuidance("Select Material of the Chamber.");
  fChamMatCmd->SetParameterName("choice", false);
  fChamMatCmd->AvailableForStates(G4State_PreInit, G4State_Idle);

  fStepMaxCmd = new G4UIcmdWithADoubleAndUnit("/NGLS/det/stepMax", this);
  fStepMaxCmd->SetGuidance("Define a step max");
  fStepMaxCmd->SetParameterName("stepMax", false);
  fStepMaxCmd->SetUnitCategory("Length");
  fStepMaxCmd->AvailableForStates(G4State_Idle);
}

NGLSDetectorMessenger::~NGLSDetectorMessenger() {
  delete fTargMatCmd;
  delete fChamMatCmd;
  delete fStepMaxCmd;
  delete fNGLSDirectory;
  delete fDetDirectory;
}

void NGLSDetectorMessenger::SetNewValue(G4UIcommand * command, G4String newValue) {
  if ( command == fTargMatCmd ) {
    fDetectorConstruction->SetTargetMaterial(newValue);
  }

  if ( command == fChamMatCmd ) {
    fDetectorConstruction->SetChamberMaterial(newValue);
  }

  if ( command == fStepMaxCmd ) {
    fDetectorConstruction
    ->SetMaxStep(fStepMaxCmd->GetNewDoubleValue(newValue));
  }
}
