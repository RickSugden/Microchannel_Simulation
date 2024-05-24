# Simulation of a soft-polymer gel under confinement in a shearing microchannel

Unlike newtonian fluids like water, non-newtonian fluids exhibit non-linear responses to stimuli. This allows for the diverse properties of substances like hair gel which can appear solid in one moment, and appear fluid when force is applied. 

One condition known to evoke non-linear behaviour from these fluids is confinement, i.e. when a fluid is restricted in space to a gap that is only a few times larger than the molecule itself (2-20X). 

In this project, I was given a large codebased developed by a collaborator that computes a 2D simulation of balls in a shearing cell. My task was to determine whether the non-linear properties of a soft polymer gel can be found to be emergent within this computer simulation. What I found was that indeed, despite no hard-coded knowledge of this fact, the non-linear properties emerged out of first and second order stress and momentum calculations. 

I developed an animation in MATLAB to visualize the simulation (colors only for tracking purposes):
<img width="829" alt="polymer_simulation_animation_screenshot" src="https://github.com/RickSugden/Microchannel_Simulation/assets/41484082/d39b3546-379f-451c-bf78-cc4f25681c53">

Flow Curves calculate the speed of the shearing cell vs the shearing stress on the gel. Straight lines indicate newtonian behaviour:

I started by looking at different packing fractions:
![loglog_flow_curve_expanded](https://github.com/RickSugden/Microchannel_Simulation/assets/41484082/b9f63cd2-e058-426f-9c60-fd473dbcbf7f)

But it required a higher packing fraction to elucidate the non-newtonian behaviour
![expanded_flow_curve1](https://github.com/RickSugden/Microchannel_Simulation/assets/41484082/6fce7838-9ac2-4e0d-b42c-c5ab447ef9ea)

