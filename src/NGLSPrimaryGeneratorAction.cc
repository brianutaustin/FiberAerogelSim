#include "NGLSPrimaryGeneratorAction.hh"

#include "G4LogicalVolumeStore.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4Event.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"

#include "Randomize.hh"

NGLSPrimaryGeneratorAction::NGLSPrimaryGeneratorAction() : G4VUserPrimaryGeneratorAction() {
  G4int nofParticles = 1;
  fParticleGun = new G4ParticleGun(nofParticles);

  // default particle kinematic
  G4ParticleDefinition * particleDefinition = G4ParticleTable::GetParticleTable()->FindParticle("proton");
  fParticleGun->SetParticleDefinition(particleDefinition);
  fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0., 0., 1.));
  fParticleGun->SetParticleEnergy(3.0 * GeV);
}

NGLSPrimaryGeneratorAction::~NGLSPrimaryGeneratorAction() {
  delete fParticleGun;
}

void NGLSPrimaryGeneratorAction::GeneratePrimaries(G4Event * anEvent) {
  // This function is called at the begining of event
  G4double worldZHalfLength = 0;
  G4LogicalVolume * worldLV
    = G4LogicalVolumeStore::GetInstance()->GetVolume("World");
  G4Box * worldBox = NULL;

  if ( worldLV ) {
    worldBox = dynamic_cast<G4Box *>(worldLV->GetSolid());
  }
  if ( worldBox ) {
    worldZHalfLength = worldBox->GetZHalfLength();
  } else {
    G4cerr << "World volume of box not found." << G4endl;
    G4cerr << "Perhaps you have changed geometry." << G4endl;
    G4cerr << "The gun will be place in the center." << G4endl;
  }

  fParticleGun->SetParticlePosition(G4ThreeVector(0., 0., -worldZHalfLength));
  fParticleGun->GeneratePrimaryVertex(anEvent);
}
