/**
  * @welcomepage.h
  * @brief Stores declaration for the WelcomePage class.
  * @author Rufei Fan
  * @3-10-2016
*/

#ifndef WELCOMEPAGE_H
#define WELCOMEPAGE_H

#include <QWidget>
/**
 * @class WelcomePage
 * @brief The WelcomePage class reprsents the initial screen that is shown when the program starts.
 * This screen houses the gameplay instructions and a play button which will actually launch
 * an instance of the Game class.
 */


class WelcomePage : public QWidget
{
    Q_OBJECT
public:
    WelcomePage(QWidget * parent=0);
public slots:
    /**
     * @brief initializes and displays an instance of the Game class
     */
    void play();

    /**
     * @brief initializes and displays an instance of the Instruction class
     */
    void instruct();
};

#endif // WELCOMEPAGE_H

