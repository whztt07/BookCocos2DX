/* ----------------------------------------------------------------------------
 *
 * Includes
 *
 * ----------------------------------------------------------------------------
 */
#include "BackgroundGameLayer.h"

/* ----------------------------------------------------------------------------
 *
 * Class methods
 *
 * ----------------------------------------------------------------------------
 */

/* ----------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------
 */
BackgroundGameLayer::~BackgroundGameLayer()
{
    
}

/* ----------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------
 */
BackgroundGameLayer* BackgroundGameLayer::create()
{
    BackgroundGameLayer* layer = new BackgroundGameLayer();
    layer->init();
    return layer;
}

/* ----------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------
 */
bool BackgroundGameLayer::init()
{
    if (!Layer::init())
    {
        return false;
    }

    // ------------------------------------------------------------------------
    // Get windows size
    // ------------------------------------------------------------------------    
    parallax = CCParallaxScrollNode::create();
    
    auto bg1 = Sprite::create("GameBackground.png");
    auto bg2 = Sprite::create("GameBackground.png");
    parallax->addInfiniteScrollXWithZ(-1,Point(0.1,0.1),Point(0, 0), bg1, bg2, NULL);
    
    this->addChild(parallax);

    //create main loop
    scheduleUpdate();

    return true;
}


/* ----------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------
 */
void BackgroundGameLayer::update(float dt)
{
    // ------------------------------------------------------------------------
    // Update parallax
    // ------------------------------------------------------------------------
    parallax->updateWithVelocity(Point(-10,0), dt);
}