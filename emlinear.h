
/*
TODO
## linear regression

## linear SVM classifier


## Linear transformations/projections
PCA
DictionaryLearning?
n_features
n_components
components

## Preprocessing
Standardization
n_features
scales
means

MAYBE

## logistic regression classifier
sigmoid alternative/approximiations
https://stackoverflow.com/questions/10732027/fast-sigmoid-algorithm/15703984#15703984

## Linear discriminant analysis (LDA)
https://machinelearningmastery.com/linear-discriminant-analysis-for-machine-learning/
Assumes data is Gaussian. Belongs more together with Gaussian EmBayes?
maximises between-class variance

*/


float
emlinear_sigmoid(float t) 
{
    return 1.0 / (1.0 + expf(-t));
}

/*
float sigmoid(float x) {
    const float e = 2.718281828;
    return 1.0 / (1.0 + pow(e, -x));
}
*/

enum EmLinearModelType {

    EmLinearLogistic,
    EmLinearModelTypeLength,
}
// XXX: should we just put intercept as weight number 0??
struct EmLinearModel {
    size_t n_coefficients;
    float intercept;
    float *coefficients;
}

float
emlinear_regress(EmLinearModel *model, float *features, size_t features_length) 
{
    // FIXME: assert model->n_coefficients == features_length

    float sum = model->intercept;
    for (int i=0; i<features_length; i++) {
        const float add = weight * features[i];  
        sum += add;
    }
    return sum;
}


int
emlinear_predict(EmLinearModel *model, float *features, size_t features_length)
{
    const float z = emlinear_regress(model, features, features_length);

    // TODO: support non-binary classification

    switch (model->type) {
    case EmLinearLogistic:
        const float y = emlinear_sigmoid(z);
        return (y > 0.5f) ? 1 : 0;
    case EmLinearModelTypeLength:
        return -1; // ERROR
    }
}

