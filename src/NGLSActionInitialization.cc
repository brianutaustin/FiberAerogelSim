#include "NGLSActionInitialization.hh"
#include "NGLSPrimaryGeneratorAction.hh"
#include "NGLSRunAction.hh"
#include "NGLSEventAction.hh"

NGLSActionInitialization::NGLSActionInitialization() : G4VUserActionInitialization() {}

NGLSActionInitialization::~NGLSActionInitialization() {}

void NGLSActionInitialization::BuildForMaster() const {
  SetUserAction(new NGLSRunAction);
}

void NGLSActionInitialization::Build() const {
  SetUserAction(new NGLSPrimaryGeneratorAction);
  SetUserAction(new NGLSRunAction);
  SetUserAction(new NGLSEventAction);
}
