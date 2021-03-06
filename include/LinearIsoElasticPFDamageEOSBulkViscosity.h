/****************************************************************/
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*          All contents are licensed under LGPL V2.1           */
/*             See LICENSE for full restrictions                */
/****************************************************************/
#ifndef LINEARISOELASTICPFDAMAGEEOSBULKVISCOSITY_H
#define LINEARISOELASTICPFDAMAGEEOSBULKVISCOSITY_H

//#include "ComputeStressBase.h"
//#include "Function.h"
#include "LinearIsoElasticPFDamage.h"

/**
 * Phase-field fracture
 * This class computes the energy contribution to damage growth
 * Small strain Isotropic Elastic formulation
 * Stiffness matrix scaled for heterogeneous elasticity property
 * Birch-Murnaghan EOS and bulk viscosity
 */
class LinearIsoElasticPFDamageEOSBulkViscosity : public LinearIsoElasticPFDamage
{
public:
  LinearIsoElasticPFDamageEOSBulkViscosity(const InputParameters & parameters);

protected:
  //virtual void computeQpStress();
  virtual void updateVar();
  //virtual void updateJacobian();

  //const VariableValue & _c;
  /// Small number to avoid non-positive definiteness at or near complete damage
  //Real _kdamage;

  //MaterialProperty<Real> & _G0_pos;
  //MaterialProperty<RankTwoTensor> & _dstress_dc;
  //MaterialProperty<RankTwoTensor> & _dG0_pos_dstrain;

  MaterialProperty<RankTwoTensor> & _strain_rate;

  const MaterialProperty<RankTwoTensor> & _mechanical_strain;
  const MaterialProperty<RankTwoTensor> & _mechanical_strain_old;

  //std::vector<RankTwoTensor> _etens;
  //std::vector<Real> _epos;
  //std::vector<Real> _eigval;
  //RankTwoTensor _eigvec;

  // exponent in Murnaghan EOS
  const Real _n_Murnaghan;

  // reference bulk modulus
  const Real _Bulk_Modulus_Ref;

  // Von Neumann coefficient
  const Real _C0;

  // Landshoff coefficient
  const Real _C1;

};

#endif //LINEARISOELASTICPFDAMAGEEOSBULKVISCOSITY_H
