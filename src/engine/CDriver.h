#ifndef CDRIVER_H
#define CDRIVER_H

#include <QPointF>
#include <QSet>
#include "Driver.h"
#include "NPCWave.h"

namespace td {

class BuildContextMenu;
class GameObject;
class MainWindow;
class Map;
class NPC;
class Player;
class PlayerContextMenu;
class Projectile;
class ResManager;
class Stream;
class Tower;
class TowerContextMenu;
class Unit;

class CDriver : public Driver {
    Q_OBJECT
  
private:
    /** The ID of the player object. */
    unsigned int playerID_;

    /** The player on this client. */
    Player* human_;

    /** The main game window, where all graphics will be drawn. */
    MainWindow* mainWindow_;
    
    /** The menu for building towers. */
    BuildContextMenu* buildContextMenu_;

    /** The menu for upgrading/selling towers. */
    TowerContextMenu* towerContextMenu_;

    /** The menu for upgrading players. */
    PlayerContextMenu* playerContextMenu_;

    /** Keeps track of how many NPCs there currently are. */
    size_t npcCounter_;
    
    /** The single instance of this class that can be created. */
    static CDriver* instance_;
    
    /** Tells objects whether or not the game is being played single player **/
    bool singlePlayer_;


    QList<NPCWave*> waves_;
    QTimer* waveTimer_;
    unsigned int timeCount_;

    CDriver(MainWindow* parent = 0);
    ~CDriver();

public:
    /**
     * Creates an instance of the class if one doesn't exist yet.
     *
     * @author Dean Morin
     * @param mainWindow A pointer to the main window where everything is drawn.
     * @returns An new instance of the class if one doesn't exist yet, or
     * if one does, it returns a pointer to that instance.
     */
    static CDriver* init(MainWindow* mainWindow);
   
    /**
     * Calls the dtor for the singleton instance.
     *
     * @author Dean Morin
     */
    static void shutdown();
   
    /**
     * Returns the instance of this Singleton class. Should only be used if
     * you know that init() has already been called.
     *
     * @author Dean Morin
     * @returns A pointer to the one available instance of this class.
     */
    static CDriver* instance() {
        return instance_;
    }

    /**
     * Connects the client driver to the server. This must be called
     * at some point before the updateServer() method is ever called,
     * as it creates the stream that updateServer() uses to push updates
     * to the server.
     * 
     * @author Duncan Donaldson
     */
    void connectToServer(const QString& servaddr);

    /**
     * Disconnects the client driver from the server,
     * and destroys the stream used to update the server, call this on cleanup.
     * 
     * @author Duncan Donaldson
     */
    void disconnectFromServer();

    /**
     * reads in an object, if it exists, updates it,
     * if it doesn't exist creates it.
     * @author Duncan Donaldson
     */
    void readObject(Stream* s);

    /**
     * Notifies the driver of an update to an object. Does nothing.
     *
     * @author Darryl Pogue
     * @param obj The GameObject that has been updated.
     */
    virtual void update(GameObject*) { }

    /**
     * Notifies the driver of a real-time update to an object.
     * This is used to build a network message sent streaming to other
     * clients to synchronize the object state.
     *
     * @author Darryl Pogue
     * @author Duncan Donaldson
     * @param obj The GameObject that has been updated.
     */
    virtual void updateRT(GameObject* obj);

    /**
     * Sends an arbitrary network message to all connected clients.
     * If you are calling this function, you are probably doing it wrong.
     *
     * @author Darryl Pogue
     * @param msgType The type of message to be sent. (See netmessages.h)
     * @param msg The message data as a byte array.
     */
    virtual void sendNetMessage(unsigned char msgType, QByteArray msg);

    /**
     * Sets the health of the player's base.
     *
     * @author Darryl Pogue
     * @param health The new base health.
     */
    virtual void setBaseHealth(int health);

    /**
     * Sets a player as the local human player object.
     * Sets event filter for key presses to be passed to PlayerInputComponent.
     * 
     * @author Tom Nightingale
     * @author Duncan Donaldson
     * @author Darryl Pogue
     * @param player The player object to make the local player.
     */
    void makeLocalPlayer(Player* player);

    /**
     * creates npc object
     * @author Marcel Vangrootheest
     * @param npcType NPC type (norm, slow, fast, fly, boss)
     * @returns the reference to an NPC
     */
    NPC* createNPC(int npcType);

    /**
     * Stop game timer.
     * 
     * @author Duncan Donaldson
     * @return void
     */
    void endGame();

    /**
     * Returns the human
     *
     * @author Terence Stenvold
     */
    Player* getHuman(){
        return human_;
    }

    /**
     * Gets a pointer to the main window where all graphics are drawn.
     *
     * @author Dean Morin, Darryl Pogue. Special thanks to Marcel Vangrootheest.
     * @return The main window where all graphics are drawn.
     */
    MainWindow* getMainWindow() {
        return mainWindow_;
    }
    /**
     * getter for SinglePlayer
     *
     * @author Duncan Donaldson
     * @return whether or not the game is being played single player.
     */
    bool isSinglePlayer();
    /**
     * sets the value of singlePlayer
     *
     * @author Duncan Donaldson
     * @param the value to set singlePlayer to.
     */
    void setSinglePlayer(bool singlePlayer);

    /**
     * Tries to add a resource to a specified BuildingTower.
     *
     * @author Marcel Vangrootheest
     * @param t The Building tower that a resource is added to.
     */
    void requestResourceAddition(BuildingTower* t);

signals:
    /**
     * Emitted when the spacebar is pressed on a resource tile.
     *
     * Connected to startHarvesting() in Player.cpp.
     *
     * @author Dean Morin
     * @param type The resource type that the player is standing on.
     */
    void signalHarvesting(int type);

    /**
     * Emmited when the spacebar is pressed on an empty tile.
     *
     * Connected to dropResource() in Player.cpp.
     *
     * @author Dean Morin
     */
    void signalEmptyTile(bool);
    
public slots:
    /**
    * Initialize and start game timer.
    * [Hijacked and updated by Tom Nightingale] 
    * Client side objects are created here.
    *
    * @author Duncan Donaldson
    * @return void
    */
    void startGame(bool singlePlayer);

    /**
     * Called whenenever the spacebar is pressed. It checks the tile type that
     * the player is currently standing on, and performs the appropriate action.
     */
    void handleSpacebarPress();

    /**
     * Requests or creates a Building Tower
     * of specified type at specified position.
     * Connected to TowerSelected in ContextMenu.
     *
     * @param type  The Tower type to be built.
     * @param pos   The position of the tower placement.
     */
    void requestBuildingTower(int type, QPointF pos);

    /**
     * Requests or sells a Tower at the player's current position.
     * Should be connected to a context menu.
     *
     * @param pos The position of the tower to sell.
     */
    void requestSellTower(QPointF pos);

    /**
     * Request to upgrade a tower at the player's current position.
     * Connected to signalupgradetower in player
     *
     * @param pos The position of the player and tower to upgrade.
     */
    void requestUpgradeTower(QPointF pos);

private slots:
    /**
     * Creates a projectile object.
     *
     * @author Pan Khantidhara, Marcel Vangrootheest, Dean Morin
     * @param projType The type of the projectile (Arrow, Cannon, etc).
     * @param source The starting point of the projectile.
     * @param target The destination point of the projectile.
     */
    //void createProjectile(int projType, QPointF source, QPointF target,
    //        Unit* enemy);

    /**
     * handles a received UDP message.
     *
     * @author Duncan Donaldson
     */
    void UDPReceived(Stream* s);

    /**
     * Creates Npc objects based on the game tick.
     *
     * @author Marcel Vangrootheest
     */
    void NPCCreator();
    void deadWave();
};

} /* end namespace td */

#endif
