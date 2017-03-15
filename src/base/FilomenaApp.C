#include "FilomenaApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

#include "LinearIsoElasticPFDamageEOS.h"
#include "LinearIsoElasticPFDamageEOSBulkViscosity.h"

template<>
InputParameters validParams<FilomenaApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

FilomenaApp::FilomenaApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  FilomenaApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  FilomenaApp::associateSyntax(_syntax, _action_factory);
}

FilomenaApp::~FilomenaApp()
{
}

// External entry point for dynamic application loading
extern "C" void FilomenaApp__registerApps() { FilomenaApp::registerApps(); }
void
FilomenaApp::registerApps()
{
  registerApp(FilomenaApp);

  registerMaterial(LinearIsoElasticPFDamageEOS);
  registerMaterial(LinearIsoElasticPFDamageEOSBulkViscosity);
}

// External entry point for dynamic object registration
extern "C" void FilomenaApp__registerObjects(Factory & factory) { FilomenaApp::registerObjects(factory); }
void
FilomenaApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void FilomenaApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { FilomenaApp::associateSyntax(syntax, action_factory); }
void
FilomenaApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
