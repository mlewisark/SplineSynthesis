#include "SplineOscillator.hpp"
#include <cmath>
#include <cstdlib>
#include <ctime>

SplineOscillator::SplineOscillator(float frequency, float tension, float gravity, float shadowDepth, float randomizationRate)
    : frequency(frequency), tension(tension), gravity(gravity), shadowDepth(shadowDepth), randomizationRate(randomizationRate), currentPhase(0) {
    srand(time(0));
}

void SplineOscillator::calculateRandomPoints() {
    // Generate two random points in coordinate plane
    float point1X = (float)rand() / RAND_MAX * 2.0f - 1.0f;  // Range: -1 to 1
    float point1Y = (float)rand() / RAND_MAX * 2.0f - 1.0f;
    
    float point2X = (float)rand() / RAND_MAX * 2.0f - 1.0f;
    float point2Y = (float)rand() / RAND_MAX * 2.0f - 1.0f;
    
    pointPositions.clear();
    pointPositions.push_back(point1X);
    pointPositions.push_back(point1Y);
    pointPositions.push_back(point2X);
    pointPositions.push_back(point2Y);
}

void SplineOscillator::computeShadowPoint() {
    if (pointPositions.size() < 4) return;
    
    float p1x = pointPositions[0];
    float p1y = pointPositions[1];
    float p2x = pointPositions[2];
    float p2y = pointPositions[3];
    
    // Calculate midpoint
    float midX = (p1x + p2x) / 2.0f;
    float midY = (p1y + p2y) / 2.0f;
    
    // Calculate distance between points
    float distance = std::sqrt((p2x - p1x) * (p2x - p1x) + (p2y - p1y) * (p2y - p1y));
    
    // Shadow point pulled downward by gravity and tension
    float shadowX = midX;
    float shadowY = midY - (gravity * distance * shadowDepth / tension);
    
    pointPositions.push_back(shadowX);
    pointPositions.push_back(shadowY);
}

void SplineOscillator::catmullRomSplineInterpolation() {
    if (pointPositions.size() < 8) return;
    
    float p0x = pointPositions[0], p0y = pointPositions[1];
    float p1x = pointPositions[2], p1y = pointPositions[3];
    float p2x = pointPositions[4], p2y = pointPositions[5];
    
    interpolationCurveData.clear();
    
    int samples = 256;
    for (int i = 0; i < samples; i++) {
        float t = (float)i / samples;
        float tt = t * t;
        float ttt = tt * t;
        
        // Catmull-Rom basis functions
        float q0 = -0.5f * ttt + tt - 0.5f * t;
        float q1 = 1.5f * ttt - 2.5f * tt + 1.0f;
        float q2 = -1.5f * ttt + 2.0f * tt + 0.5f * t;
        float q3 = 0.5f * ttt - 0.5f * tt;
        
        float interpX = q0 * p0x + q1 * p1x + q2 * p2x + q3 * pointPositions[4];
        float interpY = q0 * p0y + q1 * p1y + q2 * p2y + q3 * pointPositions[5];
        
        interpolationCurveData.push_back(interpY);
    }
}

void SplineOscillator::generateWaveformOutput() {
    calculateRandomPoints();
    computeShadowPoint();
    catmullRomSplineInterpolation();
}