#ifndef NGLSPrimaryGeneratorAction_h
#define NGLSPrimaryGeneratorAction_h 1

#include "G4VUserPrimaryGeneratorAction.hh"
#include "globals.hh"

class G4ParticleGun;
class G4Event;

class NGLSPrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction {
  public:
    NGLSPrimaryGeneratorAction();
    virtual ~NGLSPrimaryGeneratorAction();

    virtual void GeneratePrimaries(G4Event* );

    G4ParticleGun* GetParticleGun() {return fParticleGun;}

    // Set methods
    void SetRandomFlag(G4bool );

  private:
    G4ParticleGun*          fParticleGun; // G4 particle gun
};

#endif
