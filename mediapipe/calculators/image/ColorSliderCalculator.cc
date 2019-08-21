
// imports

#include "mediapipe/framework/calculator_framework.h"
#include "mediapipe/framework/port/status.h"
#include "mediapipe/framework/formats/image_frame.h"
#include "mediapipe/framework/port/ret_check.h"
#include <vector>

/*
node {
calculator:"ColorSliderCalculator"
input_stream: "Red"
input_stream: "Green"
input_stream: "Blue"
output_stream:"RGB_OUT:out_array"

}
*/


//calculator ColoSlider
namespace mediapipe {


class ColorSliderCalculator : public CalculatorBase {
public:

    ColorSliderCalculator() = default;
    ~ColorSliderCalculator() override = default;
    //ColorSliderCalculator() : initialized_(false){}

    static ::mediapipe::Status GetContract (CalculatorContract *cc){

    cc->Inputs().Index(0).Set<int>();
    cc->Inputs().Index(1).Set<int>();
    cc->Inputs().Index(2).Set<int>();

    if (cc->Outputs().HasTag("RGB_OUT")){
    cc->Outputs().Tag("RGB_OUT").Set<std::vector<int>>();

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
    int red_buffer = cc->Inputs().Index(0).Value().Get<int>();
    int green_buffer = cc->Inputs().Index(1).Value().Get<int>();
    int blue_buffer = cc->Inputs().Index(2).Value().Get<int>();


    const auto& rgb= {red_buffer, green_buffer,blue_buffer};
    cc->Outputs().Tag("RGB_OUT").Add(&rgb, cc->InputTimestamp());

    return ::mediapipe::OkStatus();
    }
  };
  } //end namespace
REGISTER_CALCULATOR(::mediapipe::ColorSliderCalculator);
