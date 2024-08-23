#pragma once
#include "HittableList.h"
#include "Sphere.h"
#include "Camera.h"
#include "Material.h"

class Scene {
public:
	Scene() = default;
	~Scene() = default;

	void Render() { camera.render(world); }

	hittable_list world;
	camera camera;
private:
};