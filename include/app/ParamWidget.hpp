#pragma once
#include <app/common.hpp>
#include <widget/OpaqueWidget.hpp>
#include <ui/Tooltip.hpp>
#include <engine/ParamQuantity.hpp>
#include <history.hpp>


namespace rack {
namespace app {


/** Manages an engine::Param on a ModuleWidget. */
struct ParamWidget : widget::OpaqueWidget {
	engine::ParamQuantity* paramQuantity = NULL;
	ui::Tooltip* tooltip = NULL;
	/** For triggering the Change event. `*/
	float lastValue = NAN;

	virtual void init() {}
	void step() override;
	void draw(const DrawArgs& args) override;

	void onButton(const event::Button& e) override;
	void onDoubleClick(const event::DoubleClick& e) override;
	void onEnter(const event::Enter& e) override;
	void onLeave(const event::Leave& e) override;

	void createContextMenu();
	void resetAction();
};


} // namespace app
} // namespace rack
