#ifndef FILOMENAAPP_H
#define FILOMENAAPP_H

#include "MooseApp.h"

class FilomenaApp;

template<>
InputParameters validParams<FilomenaApp>();

class FilomenaApp : public MooseApp
{
public:
  FilomenaApp(InputParameters parameters);
  virtual ~FilomenaApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* FILOMENAAPP_H */
