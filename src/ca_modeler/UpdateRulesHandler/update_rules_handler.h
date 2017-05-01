#ifndef UPDATE_RULES_HANDLER_H
#define UPDATE_RULES_HANDLER_H

#include "../ca_model/ca_model.h"

#include <string>

#include "update_rules_editor.h"

#include <QWidget>

#include <GLFW/glfw3.h>

namespace Ui {
class UpdateRulesHandler;
}

class UpdateRulesHandler : public QWidget
{
  Q_OBJECT

public:
  explicit UpdateRulesHandler(QWidget *parent = 0);
  ~UpdateRulesHandler();

  void set_m_ca_model(CAModel* model) {m_ca_model = model;}
  std::string GenerateCode() {return mGraphEditor.EvalGraphEditor();}

private slots:
  void UpdateEditorComboBoxes();

  void on_pbtn_open_node_graph_editor_released();

private:
  Ui::UpdateRulesHandler *ui;

  // Reference to CAModel serve to update the options of attributes and neighborhoods at editor
  CAModel* m_ca_model;

  // Reference to node graph editor (NGE) window
  GLFWwindow* mNGEWindow;

  // The Editor instance
  UpdateRulesEditor mGraphEditor;

  // Retain the state of editor window: open or closed
  bool mIsEditorOpen;
};

#endif // UPDATE_RULES_HANDLER_H