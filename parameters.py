##CAREFUL WITH THE PARSER
##IT DOES NOT HANDLE YET THE SPACE AT EOL

##type 0 = plane
##type 1 = cylinder

#mesh_file = ./meshes/regular/mirror_cylinder_13_40.off
mesh_file = ./meshes/rectangular/mirror_cylinder_13_20.off
#mesh_file = ./meshes/small.off
#mesh_file = ./meshes/seam/mirror_cylinder3_13_20.off
#mesh_file = ./meshes/strip_10.off
mesh_type = 1
has_seam = false

mass = 1.0
gamma = 1.0
temperature = 0.0
boltzmann = 1.0
diffusion = 0.001
delta_t = 0.001
is_brownian = false

number_of_steps = 100000
print_each = 1000
print_polarization_each = 10000
random_seed = 160

read_from_mdf = true
input_file = ./data/input.mdf
apply_ic = false
add_noise = false
noise_strength = 0.1


stretching_on = true
stretching_rigidity1 = 40000.0
stretching_rigidity2 = 40000.0
stretching_rigidity3 = 40000.0
stretching_rigidity4 = 1000.0
stretching_rigidity5 = 1000.0
bond_length = 1.0
bond_length1 = 1.1
bond_length2 = 0.9

bending_on = true
###quartic parameters pA=pA*bending_rigidity2, etc.
harmonic = false
bending_rigidity2 = 1000.0
#pA = 7.07528525767
#pA = 12.7249235208
pA = 3.35433449858
##B should have the opposite signe of angle_1
#pB = 3.46868267506
#pB = 6.05631550747
pB = 2.96091730641
#pC = 0.256623796517
#pC = 0.377125392344
pC = 0.292047010495
#where to put heaviside
#barrier = -0.0586900522814
#barrier = -0.0479559080806
barrier = -0.0740353398693

#quadratic parameters
bending_rigidity1 = 200.0
bending_rigidity3 = 1500.0
bending_rigidity4 = 500.0
bending_rigidity5 = 500.0

##in fact those are sin(alpha) and  MINUS:towards exterior
angle_1 = 0.0
angle_2 = -0.588
#angle_3 is specified with a calculate_angle trick
angle_3 = 0.0
angle_4 = 0.0
angle_5 = 0.0

##COOPERATIVITY
coop_coef = 50.0

#clamping between the z-component=[boundary0,boundary1]
is_clamped = true
boundary0 = 39.1
boundary1 = 40.1

##SPIN
spin_on = false
deltaE = 1.0
JJ = 100.0

##FORCE on NODES
nodal_on = false
nodal_strength = 0.0

force_is_gradual = false
force_strength = 0.001
boundary2 = -0.1

#MOMENT on NODES
moment_on = true
moment_is_gradual = false

moment_strength = -200.0
moment_boundary_up = 0.1
moment_boundary_down = -0.1


##CONTAINER
container_on = false
container_rigidity = 0.01
container_radius = 19.0

