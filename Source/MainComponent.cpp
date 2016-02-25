/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"


//==============================================================================
MainContentComponent::MainContentComponent() : layout (Layout::LeftToRight, this)
{
    // Juce resizer to demo updates
    resizeConstraints = new ComponentBoundsConstrainer();
    resizeConstraints->setMinimumSize(400, 250);
    resizer = new ResizableCornerComponent (this, resizeConstraints);

    
    // minimal example
    Layout* minimal = layout.addSubLayout (Layout::TopDown);
    gain.setSliderStyle  (Slider::RotaryHorizontalVerticalDrag);
    phase.setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    pan.setSliderStyle   (Slider::RotaryHorizontalVerticalDrag);
    gain.setTextBoxStyle  (Slider::TextBoxBelow, true, 40, 18);
    phase.setTextBoxStyle (Slider::TextBoxBelow, true, 40, 18);
    pan.setTextBoxStyle   (Slider::TextBoxBelow, true, 40, 18);
    addAndMakeVisible (gain);
    addAndMakeVisible (phase);
    addAndMakeVisible (pan);
    minimal->addComponent (&gain);      // <- this is the only line necessary for each component
    minimal->addComponent (&phase);
    minimal->addComponent (&pan);
    
    // other use cases
    // add some sliders in a column
    Layout* column = layout.addSubLayout (Layout::TopDown);
    for (int i=0; i<5; ++i) {
        Slider* slider = new Slider (Slider::LinearHorizontal, Slider::TextBoxBelow);
        components.add (slider);
        column->addComponent (slider);
        addAndMakeVisible (slider);
    }
    
    // you can also access the component from the item
    LayoutItem* item = layout.addComponent (new Label ("some text", "Some Text"));
    components.add (item->getComponent());
    addAndMakeVisible (item->getComponent());
    
    // in another column we use a spacer
    Layout* column3 = layout.addSubLayout (Layout::BottomUp);
    for (int i=0; i<5; ++i) {
        TextButton* button = new TextButton ("Button " + String (i+1));
        components.add (button);
        column3->addComponent (button);
        addAndMakeVisible (button);
    }
    column3->addSSpacer();
    
    Layout* column4 = layout.addSubLayout (Layout::TopDown);
    for (int i=0; i<3; ++i) {
        Label* label;
        Slider* slider = new Slider (Slider::RotaryHorizontalVerticalDrag, Slider::NoTextBox);
        components.add (slider);
        column4->addLabeledComponent (slider, Layout::TopDown, &label);
        label->setText ("Knob " + String(i+1), dontSendNotification);
        label->setJustificationType (Justification::centred);
        addAndMakeVisible (slider);
    }
        
    // juce again
    setSize (600, 400);
    addAndMakeVisible (resizer);
}

MainContentComponent::~MainContentComponent()
{
}

void MainContentComponent::paint (Graphics& g)
{
}

void MainContentComponent::resized()
{
    resizer->setBounds (getRight()-16, getBottom()-16, 16, 16);
    
    layout.updateGeometry (getLocalBounds());
}
