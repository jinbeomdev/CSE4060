#include "objloader.h"
#include <cassert>
#include <algorithm>

bool loadOBJ(
	const char * path,
	std::vector<float>& out_vertices,
	std::vector<float>& out_elements) {
	printf("Loading OBJ file %s...\n", path);

	FILE * file = fopen(path, "r");
	if (file == NULL) {
		printf("Impossible to open the file\n");
		getchar();
		return false;
	}


	glm::vec3 max;
	glm::vec3 min;
	while (1) {

		char lineHeader[128];
		int res = fscanf(file, "%s", lineHeader);
		if (res == EOF)
			break;

		if (strcmp(lineHeader, "v") == 0) {
			glm::vec3 vertex;
			fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
			out_vertices.push_back(vertex.x);
			out_vertices.push_back(vertex.y);
			out_vertices.push_back(vertex.z);

			max[0] = std::max(max[0], vertex.x);
			max[1] = std::max(max[1], vertex.y);
			max[2] = std::max(max[2], vertex.z);
			min[0] = std::min(min[0], vertex.x);
			min[1] = std::min(min[1], vertex.y);
			min[2] = std::min(min[2], vertex.z);

		} else if (strcmp(lineHeader, "f") == 0) {
			std::string vertex1, vertex2, vertex3;
			unsigned int vertexIndex[3], normalIndex[3];
			int matches = fscanf(file, "%d//%d %d//%d %d//%d\n", &vertexIndex[0], &normalIndex[0], &vertexIndex[1], &normalIndex[1], &vertexIndex[2], &normalIndex[2]);
			if (matches != 6) {
				printf("File can't be read\n");
				fclose(file);
				return false;
			}
			out_elements.push_back(vertexIndex[0] - 1);
			out_elements.push_back(vertexIndex[1] - 1);
			out_elements.push_back(vertexIndex[2] - 1);
		} else {
			// Probably a comment, eat up the rest of the line
			char stupidBuffer[1000];
			fgets(stupidBuffer, 1000, file);
		}
	}

	int nom = (max[0] < max[1]) ? max[1] : max[0];
	nom = (nom < max[2]) ? max[2] : nom;

	for (int i = 0; i < out_vertices.size(); i++) {
		out_vertices[i] = out_vertices[i] / nom;
	}

	fclose(file);
	return true;
}
