
#[derive(Clone, Debug, PartialEq)]
pub struct TextSpan {
    start: usize,
    end: usize,
}

#[derive(Clone, Debug, PartialEq)]
pub struct NodeMeta {
    pub text_span: TextSpan
}

#[derive(Clone, Debug, PartialEq)]
pub enum Expr {}


// Special stuff:

#[derive(Clone, Debug, PartialEq)]
pub enum Operator {
    Add,
    Sub,
    Mul,
    Div,
    Mod,
}

#[derive(Clone, Debug, PartialEq)]
pub enum VariantValue {
    Undefined,
    Null,
    Bool(bool),
    Number(f64),
    String(String),
}

pub enum RawVariantValue {
    Double,
    Integer,
    String,
    Char,
}

#[derive(Clone, Debug, PartialEq)]
pub struct Variant {
    pub meta: NodeMeta,
    pub value: VariantValue
}

#[derive(Clone, Debug, PartialEq)]
pub struct RawVariant {
    pub meta: NodeMeta,
    pub value:
}

#[derive(Clone, Debug, PartialEq)]
pub struct LabelInfo {
    pub meta: NodeMeta,
    pub line_number:
}

// Regular stuff:

#[derive(Clone, Debug, PartialEq)]
pub struct ArrayExpression {
    pub meta: NodeMeta,
    pub contents: ListExpression
}

#[derive(Clone, Debug, PartialEq)]
pub struct AssignmentExpression {
    pub meta: NodeMeta,
    pub variable: Expr,
    pub expression: Expr,
    pub literal: Variant,
    pub shorthand: bool,
}

#[derive(Clone, Debug, PartialEq)]
pub struct BinaryExpression {
    pub meta: NodeMeta,
    pub operator: Operator,
    pub left: Expr,
    pub right: Expr,
    pub literal_left: Variant,
    pub literal_right: Variant,
}

#[derive(Clone, Debug, PartialEq)]
pub struct BreakStatement {
    pub meta: NodeMeta,
}
