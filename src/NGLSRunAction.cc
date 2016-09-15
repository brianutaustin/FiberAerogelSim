#include "NGLSRunAction.hh"

#include "G4Run.hh"
#include "G4RunManager.hh"

NGLSRunAction::NGLSRunAction() : G4UserRunAction() {
  // set printing event number per each 100 events
  G4RunManager::GetRunManager()->SetPrintProgress(1000);
}

NGLSRunAction::~NGLSRunAction() {
}

void NGLSRunAction::BeginOfRunAction(const G4Run *) {
  // inform the runManager to save random number seed
  G4RunManager::GetRunManager()->SetRandomNumberStore(false);
}

void NGLSRunAction::EndOfRunAction(const G4Run *) {
}
