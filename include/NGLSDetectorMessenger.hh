#ifndef NGLSDetectorMessenger_h
#define NGLSDetectorMessenger_h 1

#include "globals.hh"
#include "G4UImessenger.hh"

class NGLSDetectorConstruction;
class G4UIdirectory;
class G4UIcmdWithAString;
class G4UIcmdWithADoubleAndUnit;

class NGLSDetectorMessenger: public G4UImessenger {
  public:
    NGLSDetectorMessenger(NGLSDetectorConstruction* );
    virtual ~NGLSDetectorMessenger();

    virtual void SetNewValue(G4UIcommand*, G4String);

  private:
    NGLSDetectorConstruction*  fDetectorConstruction;

    G4UIdirectory*           fNGLSDirectory;
    G4UIdirectory*           fDetDirectory;

    G4UIcmdWithAString*      fTargMatCmd;
    G4UIcmdWithAString*      fChamMatCmd;

    G4UIcmdWithADoubleAndUnit* fStepMaxCmd;
};

#endif
