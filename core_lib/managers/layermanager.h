#ifndef LAYER_MANAGER_H
#define LAYER_MANAGER_H

#include "basemanager.h"

class Layer;

class LayerManager : public BaseManager
{
    Q_OBJECT

public:
    LayerManager( QObject* pParant );
    ~LayerManager();
    bool init() override;

    // Layer Management
    Layer* currentLayer();
    Layer* currentLayer( int incr );
    int currentLayerIndex();
    void setCurrentLayer( int );
    int count();

    void gotoNextLayer();
    void gotoPreviouslayer();

    // KeyFrame Management
    int  LastFrameAtFrame( int frameIndex );
    int  currentFramePosition();
    void setCurrentKeyFrame( int );
    int  firstKeyFrameIndex();
    int  lastKeyFrameIndex();

    void gotoLastKeyFrame();
    void gotoFirstKeyFrame();

    int  projectLength();

signals:
    void currentKeyFrameChanged( int n );
    void currentLayerChanged( int n );

private:
    int m_currentLayerIndex; // the current layer to be edited/displayed
    int m_currentFrameIndex; // the current key frame to be edited/displayed
};

#endif
