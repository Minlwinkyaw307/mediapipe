
// imports

#include "mediapipe/framework/calculator_framework.h"
#include "mediapipe/framework/port/status.h"
#include "mediapipe/framework/formats/image_frame.h"
#include "mediapipe/framework/port/ret_check.h"
#include <vector>
//calculator Slider_
namespace mediapipe {


class ColorSliderCalculator : public CalculatorBase {
public:

    ColorSliderCalculator() = default;
    ~ColorSliderCalculator() override = default;
    //ColorSliderCalculator() : initialized_(false){}

    static ::mediapipe::Status GetContract (CalculatorContract *cc){
    if (cc->Inputs().HasTag('Red')){
      cc->Inputs().Tag('Red').Set<int>();
      }


    if (cc->Inputs().HasTag('Green')){
    cc->Inputs().Tag('Green').Set<int>();
    }

    if (cc->Inputs().HasTag('Blue')){
    cc->Inputs().Tag('Blue').Set<int>();
    }
    if (cc->Outputs().HasTag('RGB_OUT')){
    cc->Outputs().Tag('RGB_OUT).Set<std::vector>();

    }

    return ::mediapipe::OkStatus();

    }

    ::mediapipe::Status Open(CalculatorContext* cc) override{
    return ::mediapipe::OkStatus();
    }

    ::mediapipe::Status Process(CalculatorContext* cc) override{
    if (cc->Inputs().NumEntries() == 0) {
          return tool::StatusStop();
        }
    int red_buffer = cc->Inputs().Tag('Red').Value().Get<int>();
    int green_buffer = cc->Inputs().Tag('Green').Value().Get<int>();
    int blue_buffer = cc->Inputs().Tag('Blue').Value().Get<int>();


    vector<int> rgb= {red_buffer, green_buffer,blue_buffer};
    cc->Outputs().Tag('RGB_OUT').Add(rgb, cc->InputTimestamp());

    return ::mediapipe::OkStatus();
    }
    }
    }



REGISTER_CALCULATOR(::mediapipe::ColorSiderCalculator);
