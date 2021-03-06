#pragma once

#include <map>
#include <memory>
#include <string>

#include <QWidget>

class QEvent;

namespace geometrize
{

namespace dialog
{
class ScriptEditorWidget;
}

namespace task
{
class ImageTask;
}

}

namespace geometrize
{

namespace dialog
{

/**
 * @brief The ImageTaskShapeScriptingPanel models the UI for the script editors for controlling image task shape setup, mutation etc.
 */
class ImageTaskShapeScriptingPanel : public QWidget
{
    Q_OBJECT

public:
    explicit ImageTaskShapeScriptingPanel(QWidget* parent = nullptr);
    virtual ~ImageTaskShapeScriptingPanel();

    /**
     * @brief setImageTask Sets the current image task manipulated by the scripting panel.
     * @param task Non-owning pointer to the image task that the scripting panel on this widget will manipulate.
     */
    void setImageTask(task::ImageTask* task);

    /**
     * @brief syncUserInterface Syncs the user interface with the current image task.
     * This should be called after setting a new image task, or new task settings.
     */
    void syncUserInterface();

    std::map<std::string, std::string> getScripts() const;

signals:
    void signal_scriptingToggled(bool enabled);
    void signal_scriptsReset();
    void signal_scriptChanged(const std::string& functionName, const std::string& code);

protected:
    void changeEvent(QEvent*) override;

private:
    class ImageTaskShapeScriptingPanelImpl;
    std::unique_ptr<ImageTaskShapeScriptingPanelImpl> d;
};

}

}
